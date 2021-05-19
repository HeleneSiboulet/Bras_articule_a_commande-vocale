#include <SoftwareSerial.h>

int message = 0;
int R = 2;
int G = 3;
int B = 4;



SoftwareSerial BTSerial (10,11);    // TX : 10    RX: 11

void setup() {
  Serial.begin (9600);
  BTSerial.begin (9600);
  
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode (8,INPUT);
  
}

void loop() {
  
  if (BTSerial.available() > 0 ){message = (BTSerial.read()-48);}
  //Serial.println (message);


if (digitalRead (8) == 1){
  BTSerial.write("1");;
  }
  
else {
  BTSerial.write("0");
  }



  digitalWrite(R,0);
  digitalWrite(G,0);
  digitalWrite(B,0);

  switch (message){
  
  case 7:
  digitalWrite(R,1);
  break;

  case 8:
  digitalWrite(G,1);
  break;

  case 9:
  digitalWrite(B,1);
  break;
  }

 

  delay(50);
}
