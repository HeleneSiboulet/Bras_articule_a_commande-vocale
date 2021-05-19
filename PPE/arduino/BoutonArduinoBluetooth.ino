#include <SoftwareSerial.h>

SoftwareSerial BTSerial (10,11);    // TX : 10    RX: 11

void setup() {

  Serial.begin (9600);
  BTSerial.begin (9600);
  pinMode(2,OUTPUT);
  pinMode (8,INPUT);
  
}

void loop() {

/*int message = BTSerial.read();
Serial.println (message) ;


if (message == 1){
  digitalWrite(2,HIGH);}

if (message == 0){
  digitalWrite(2,LOW);}

BTSerial.write(0);

  delay(10);*/

if (digitalRead (8) == 1){
  BTSerial.write("1");
  Serial.println("oui");}
  
if (digitalRead (8) == 0){
  BTSerial.write("0");
  Serial.println("non");}
  delay(200);

Serial.println(BTSerial.readString());
}
