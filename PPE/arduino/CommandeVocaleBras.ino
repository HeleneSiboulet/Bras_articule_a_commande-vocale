 #include <SoftwareSerial.h>

int message = 0;
bool arret;
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

  
  if (BTSerial.available() > 0 ){message = (BTSerial.read());}
  Serial.println (message);

  if (digitalRead (8) == 1) {
     BTSerial.write("1");}
  else {
     BTSerial.write("0");}

/*if (arret == false){
 switch (message){

case 97: //avant
  //sortir vein bas;
break;

case 98: //arrière
  //rentrer verin bas;
break;

/*case 99: // droite
break;

case 100: // gauche
break;*/

/*case 101: // haut
  //sortir verin haut;
break;

case 102: //bas
  //rentre verin haut
break;

/*case 103: //positif
  if (anglServo > 10){
  anglServo = anglServo - pasServo;}
  analogWrite (12,anglServo);
break;

case 104: //negatif
  if (anglServo < 250){
  anglServo = anglServo + pasServo;}
  analogWrite (12,anglServo);
break;*/

/*case 105: //attrape
  analogWrite (13,45);
break;

case 106: //lâche
  analogWrite (13,120);
break;

//case 107   // arrêt
//break;

 }}   */


                                                             
if (message != 101 && message != 102 && message != 97 && message != 98){    //couper vérins
digitalWrite(6,0);
digitalWrite(7,0);
digitalWrite(4,0);
digitalWrite(9,0);} 


if (digitalRead(8) == 1 or message == 107){arret = true;}
else{arret = false;} 

  delay(20);
}
