from pox.core import core
import pox.openflow.libopenflow_01 as of
from pox.lib.util import dpid_to_str, str_to_dpid
from pox.lib.util import str_to_bool
import pox.openflow.discovery
from pox.openflow.discovery import Discovery
import time

log = core.getLogger()

# We don't want to flood immediately when a switch connects.
# Can be overriden on commandline.
_flood_delay = 0

class preventLoopLearningSwitch (object):
  def __init__ (self, connection, transparent):
    # Switch we'll be adding L2 learning switch capabilities to
    self.connection = connection
    self.transparent = transparent

    # Our table
    self.macToPort = {}

    # We want to hear PacketIn messages, so we listen
    # to the connection
    connection.addListeners(self)

    # We just use this to know when to log a helpful message
    self.hold_down_expired = _flood_delay == 0

    #log.debug("Initializing LearningSwitch, transparent=%s",
    #          str(self.transparent))

  def _handle_PacketIn (self, event):
    """
    Handle packet in messages from the switch to implement above algorithm.
    """

    packet = event.parsed

    def flood (message = None):
      """ Floods the packet """
      msg = of.ofp_packet_out()
      if time.time() - self.connection.connect_time >= _flood_delay:
        # Only flood if we've been connected for a little while...

        if self.hold_down_expired is False:
          # Oh yes it is!
          self.hold_down_expired = True
          log.info("%s: Flood hold-down expired -- flooding",
              dpid_to_str(event.dpid))

        if message is not None: log.debug(message)
        #log.debug("%i: flood %s -> %s", event.dpid,packet.src,packet.dst)
        # OFPP_FLOOD is optional; on some switches you may need to change
        # this to OFPP_ALL.
        msg.actions.append(of.ofp_action_output(port = of.OFPP_FLOOD))
      else:
        pass
        #log.info("Holding down flood for %s", dpid_to_str(event.dpid))
      msg.data = event.ofp
      msg.in_port = event.port
      self.connection.send(msg)

    def drop (duration = None):
      """
      Drops this packet and optionally installs a flow to continue
      dropping similar ones for a while
      """
      if duration is not None:
        if not isinstance(duration, tuple):
          duration = (duration,duration)
        msg = of.ofp_flow_mod()
        msg.match = of.ofp_match.from_packet(packet)
        msg.idle_timeout = duration[0]
        msg.hard_timeout = duration[1]
        msg.buffer_id = event.ofp.buffer_id
        self.connection.send(msg)
      elif event.ofp.buffer_id is not None:
        msg = of.ofp_packet_out()
        msg.buffer_id = event.ofp.buffer_id
        msg.in_port = event.port
        self.connection.send(msg)

    self.macToPort[packet.src] = event.port # 1

    if not self.transparent: # 2
      if packet.type == packet.LLDP_TYPE or packet.dst.isBridgeFiltered():
        drop() # 2a
        return

    if packet.dst.is_multicast:
      flood() # 3a
    else:
      if packet.dst not in self.macToPort: # 4
        flood("Port for %s unknown -- flooding" % (packet.dst,)) # 4a
      else:
        port = self.macToPort[packet.dst]
        if port == event.port: # 5
          # 5a
          log.warning("Same port for packet from %s -> %s on %s.%s.  Drop."
              % (packet.src, packet.dst, dpid_to_str(event.dpid), port))
          drop(10)
          return
        # 6
        log.debug("installing flow for %s.%i -> %s.%i" %
                  (packet.src, event.port, packet.dst, port))
        msg = of.ofp_flow_mod()
        msg.match = of.ofp_match.from_packet(packet, event.port)
        msg.idle_timeout = 10
        msg.hard_timeout = 30
        msg.actions.append(of.ofp_action_output(port = port))
        msg.data = event.ofp # 6a
        self.connection.send(msg)


class noLoopController (object):
  """
  Waits for OpenFlow switches to connect and makes them learning switches.
  """
  def __init__ (self, transparent, ignore = None):
    core.openflow.addListeners(self)
    core.openflow_discovery.addListeners(self)
    self.transparent = transparent
    self.ignore = set(ignore) if ignore else ()
    self.switch_ports={} #Nästlad-dictionary, hjälper till att hålla koll hur kopplingen sker mellan switchar och portar.
    self.switch_connections={} #Denna hjälper min kontroller att prata med specifika switches med DPID.
    self.s3_port_to_s2=None

  def _handle_ConnectionUp (self, event):
    self.switch_connections[event.dpid] = event.connection #spara connection objekt när en switch ansluter sig.
    if event.dpid in self.ignore:
      log.debug("Ignoring connection %s" % (event.connection,))
      return
    log.debug("DEBUG ConnectionUp: dpid=%s (%s)", event.dpid, dpid_to_str(event.dpid))
    preventLoopLearningSwitch(event.connection, self.transparent)

  #Hantera länk evet från discovery
  def _handle_LinkEvent(self, event):
    link=event.link
    #Säkerställ att DPID behandlas som heltal
    try:
      d1 = str_to_dpid(link.dpid1) if isinstance(link.dpid1, str) else link.dpid1
      d2 = str_to_dpid(link.dpid2) if isinstance(link.dpid2, str) else link.dpid2
    except:
      d1, d2 = link.dpid1, link.dpid2
    p1 = link.port1
    p2 = link.port2
    #Skapa entries för swithcarna om de inte finns
    self.switch_ports.setdefault(d1, {})
    self.switch_ports.setdefault(d2, {})
    #Om länk upptäcks
    if event.added:
      log.info("Länk upptäckt: %s:%s <-> %s:%s", d1,p1,d2,p2)
      #Uppdatera topo-mappningen åt båda hållen
      self.switch_ports[d1][d2] = p1
      self.switch_ports[d2][d1] = p2
      #Om s3 är kopplad mot s4 OCH s2, stäng porten mot s2.
      if(3 in self.switch_ports and 2 in self.switch_ports[3] and 4 in self.switch_ports[3]):
        self.s3_port_to_s2=self.switch_ports[3][2] #Detta är den exakta porten som går från s3 till s2
        conn=self.switch_connections.get(3) #Hämta kopplingen POX <-> s3
        if conn:
          try:
            msg=of.ofp_port_mod() #Skapa port-mod meddelande.
            msg.port_no=self.s3_port_to_s2 #Anpassa på portar angivna här
            msg.hw_addr=conn.ports[self.s3_port_to_s2].hw_addr #Hämta portens MAC-adress från kopplings-objektet
            msg.config=of.OFPPC_PORT_DOWN #Stäng port/portar
            msg.mask=of.OFPPC_PORT_DOWN
            conn.send(msg) #Skicka meddelandet till switchen
            log.info("Blockerat: S3 port %s satt till DOWN", self.s3_port_to_s2)
          except Exception as e:
            log.exception("Kan ej blockera port s3<->s2: %s", e)
    #Om länk tas bort
    elif event.removed:
      log.info("Länk nere: %s:%s <-> %s:%s", d1,p1,d2,p2)
      #Uppdatera min mappning
      self.switch_ports[d1].pop(d2, None)
      self.switch_ports[d2].pop(d1, None)
      #Om s3<->s4 down, ta upp länken s3<->s2
      if{d1, d2} == {3, 4} and self.s3_port_to_s2:
        conn = self.switch_connections.get(3)
        if conn:
          try:
            #öppna porten s3 till s2
            pm=of.ofp_port_mod()
            pm.port_no=self.s3_port_to_s2
            pm.hw_addr=conn.ports[self.s3_port_to_s2].hw_addr #MAC-adressen måste med annars ignorerar switchen meddelandet
            pm.config=0 #Rensa alla config-flaggor
            pm.mask=of.OFPPC_PORT_DOWN #Just denna flagga ska påverkas
            conn.send(pm) #Skicka order till switch, effekt av detta är att port sätts upp igen
            log.info("Öppna: S3 port %s satt till UPP", self.s3_port_to_s2)
          except Exception as e:
            log.exception("Kan ej öppna port s3<->s2: %s", e)
          try: #Flusha flöden för den porten
            flush=of.ofp_flow_mod()
            flush.command=of.OFPFC_DELETE
            flush.match.in_port=of.ofp_match()
            flush.match.in_port=self.s3_port_to_s2
            conn.send(flush)
            log.info("Flöden rensats på S3 för in_port=%s", self.s3_port_to_s2)
          except Exception as e:
            log.exception("Kunde ej flusha flöden på S3: %s", e)

def launch (transparent=False, hold_down=_flood_delay, ignore = None):
  try:
    global _flood_delay
    _flood_delay = int(str(hold_down), 10)
    assert _flood_delay >= 0
  except:
    raise RuntimeError("Expected hold-down to be a number")

  if ignore:
    ignore = ignore.replace(',', ' ').split()
    ignore = set(str_to_dpid(dpid) for dpid in ignore)

  core.registerNew(noLoopController, str_to_bool(transparent), ignore)
