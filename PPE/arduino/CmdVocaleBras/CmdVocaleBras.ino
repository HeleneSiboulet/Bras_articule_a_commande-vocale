#include <SoftwareSerial.h>

int message = 0;
bool arret;
int anglServo = 100;
float angS = 100;
float pasServo = 1.0;
int E1 = 5;
int M1 = 4;
int E2 = 6;
int M2 = 7;


SoftwareSerial BTSerial (10,11);    // TX : 10    RX: 11

void setup() {
  
  Serial.begin (9600);
 BTSerial.begin (9600);

  pinMode (8,INPUT);
  
}

void loop() {
int value;
value=200;
  
  if (BTSerial.available() > 0 ){message = (BTSerial.read());}
 Serial.println (message);

  if (digitalRead (8) == 1) {
     BTSerial.write("1");}
  else {
     BTSerial.write("0");}

if (arret == false){
 switch (message){

case 97: //avant
  digitalWrite(M1, 0);//sortir verin bas;
  digitalWrite(E1,value);
break;

case 98: //arrière
  digitalWrite(M1,1);//rentrer verin bas;
  digitalWrite(E1,value);
break;

/*case 99: // droite
break;

case 100: // gauche
break;*/

case 101: // haut
  digitalWrite(M2,0);//sortir verin haut;
  digitalWrite(E2,value);
break;

case 102: //bas
  digitalWrite(M2,1);//rentre verin haut
  digitalWrite(E2,value);
break;

case 103: //positif
  if (anglServo > 10){
  angS = angS - pasServo;
  anglServo = angS;}
  analogWrite (12,anglServo);
break;

case 104: //negatif
  if (anglServo < 250){
  angS = angS + pasServo;
  anglServo = angS;}
  analogWrite (12,anglServo);
break;

case 105: //attrape
  analogWrite (13,45);
break;

case 106: //lâche
  analogWrite (13,120);
break;

//case 107
//break;

 }}


                                                             
if (message != 101 && message != 102 && message != 97 && message != 98){    //tout couper
digitalWrite(E1,0);
digitalWrite(E2,0);
digitalWrite(M1,0);
digitalWrite(M2,0);} 




if (digitalRead(8) == 1 or message == 107){arret = true;}
else{arret = false;} 

  delay(20);
}
