#Python 3
#Filnamn: hual2302_3.2_v1.py
#Skrivet av: Hussein Shaker
#Skapat datum: 2023-09-26
#Kurs: Grundläggande datavetenskap
#Handledare: Karl Pettersson
#Beskrivning: Denna programkod räknar ut största gemensamma nämnaren till två tal.

M = int(input('Skriv in det stora talet här: '))
N = int(input('Skriv in det mindre talet här: '))
r = M % N
while r != 0:  #Så länge resten inte är noll så körs koderna nedan.
    M = N  #Sätter det största talet till det mindre talet.
    N = r  #Sätter det mindre talet till resten.
    r = M % N #Räknar ut en ny rest som använder de nya M&N
print ('Talens största gemensamma nämnaren är:', (N)) #Körs efter att loopen är klar. 