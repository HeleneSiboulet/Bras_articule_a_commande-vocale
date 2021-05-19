#include <SoftwareSerial.h>

SoftwareSerial mavoieserie(10, 11);

void setup() {
  pinMode (2,OUTPUT);
  Serial.begin (9600);
  mavoieserie.begin(9600);


}

void loop() {
  //if (mavoieserie.available()) {
    Serial.print (mavoieserie.read());
    //}
  /*while (Serial.available() == 0) {};
  char b = mavoieserie.read();
  if(b == 1){
    digitalWrite (2,1); }
  if(b == 0){
    digitalWrite (2,0); }
  Serial.println(b);*/
  
delay (500);
}
