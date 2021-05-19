#include <SoftwareSerial.h>

#define rxPin 11 // Broche 11 en tant que RX, à raccorder sur TX du HC-05
#define txPin 10 // Broche 10 en tant que TX, à raccorder sur RX du HC-05
SoftwareSerial mySerial(rxPin, txPin);

int i;

void setup() {

 pinMode(rxPin, INPUT);
 pinMode(txPin, OUTPUT);
 mySerial.begin(38400);
 Serial.begin(38400);

 pinMode (2,OUTPUT);

} 

/*void loop(){
  if (mySerial.available()){
    i = mySerial.read();
    Serial.println (i);
    }
  else{Serial.print(5);}
  //if ( i == 0){digitalWrite(2,0);}
  //if ( i == 1){digitalWrite(2,1);}
  delay(50);
  }*/








void loop()
{
int i = 0;
char someChar[32] = {0};
// when characters arrive over the serial port...
if(Serial.available()) {
 do{
 someChar[i++] = Serial.read();
 delay(3);
 }while (Serial.available() > 0);
 mySerial.println(someChar);
 Serial.println(someChar);
}
while(mySerial.available())
 Serial.print((char)mySerial.read());
}
