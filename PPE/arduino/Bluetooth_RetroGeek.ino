#include <SoftwareSerial.h>

SoftwareSerial BTSerial (10,11);    // TX : 10    RX: 11

void setup() {

  Serial.begin (9600);
  BTSerial.begin (9600);
  pinMode(2,OUTPUT);
  
}

void loop() {

String message = BTSerial.readString();
//Serial.println (message) ;
delay(10);

if (message == "a"){
  digitalWrite(2,HIGH);}

if (message == "e"){
  digitalWrite(2,LOW);}
}
