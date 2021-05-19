
#include <SoftwareSerial.h>

int message = 0;
int R = 2;
int G = 3;
int B = 4;


SoftwareSerial BTSerial (10,11);    // TX : 10    RX: 11

void setup() {
  Serial.begin (9600);
  BTSerial.begin (9600);

}

void loop() {
  
  if (BTSerial.available() > 0 ){message = (BTSerial.read()-48);}
  Serial.println (message);

if (message==1){digitalWrite(R,1);}
if (message==2){digitalWrite(G,1);}
if (message==3){digitalWrite(B,1);}


if (message==5){digitalWrite(R,0);}
if (message==6){digitalWrite(G,0);}
if (message==7){digitalWrite(B,0);}



   

  delay(100);
}
