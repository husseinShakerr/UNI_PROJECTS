#include <Arduino.h>
#include <SoftwareSerial.h>
String tmp;

void setup() {
  Serial.begin(1200);
  Serial.println("Enter 10 chars");

}

void loop() {
  //Denna loop går tills det finns data tillgänglig på seriell porten. 
  while(Serial.available() == 0){
  }
  //Läser in strängen tills en radbrytning dyker upp.
  tmp = Serial.readStringUntil('\n');
  tmp.trim(); //Rensar onödiga tecken.
  Serial.println(tmp); //Skriver ut strängen.
}
