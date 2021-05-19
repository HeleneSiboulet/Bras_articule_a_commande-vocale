 #include <SoftwareSerial.h>
 #include <Servo.h>
Servo servohorizon;
Servo servopince;

int message = 0;
bool arret = true;
int E1 = 5;
int M1 = 4;
int E2 = 6;
int M2 = 7;
double alpha0;
double beta0;
double alpha1;
double beta1;
double pas = 0.1;
float x = 100;
float y = 100;
int value = 200;
float a = 350;
double pi = 3.141592654;

SoftwareSerial BTSerial (10,11);    // TX : 10    RX: 11

void setup() {

  pinMode (M1, OUTPUT);
  pinMode (M2, OUTPUT);
  servohorizon.attach(13);
  pinMode (13,OUTPUT);
  servopince.attach(12);
  pinMode (12,OUTPUT);
 
  
 Serial.begin (9600);
 BTSerial.begin (9600);

  pinMode (2,INPUT);

}

void loop() {
  

 
 alpha0 = (-16/7 )* analogRead (A5) + 920/7;
 beta0  = (64/221)* analogRead (A3) + (12752/251);
 alpha1 = (acos(x/(sqrt(x*x + y*y))) + acos((sqrt(x*x + y*y)))/(2*a))*180/pi;
 beta1  = (pi - 2 *acos((sqrt(x*x + y*y))/(2*a)))*180/pi;
 
 Serial.print ("x=");
 Serial.print (x);
 Serial.print ("  y=");
 Serial.print (y);
 Serial.print ("  potenB");
 Serial.print (analogRead(A3) );
 Serial.print ("   alpha0=");
 Serial.print (alpha0);
 Serial.print ("  beta0=");
 Serial.print (beta0);
 Serial.print ("  alpha1 =");
 Serial.print (alpha1);
 Serial.print ("  beta1=");
 Serial.println (beta1);
 
  if (BTSerial.available() > 0 ){message = (BTSerial.read());}
  Serial.println (message);

  if (digitalRead (2) == 1) {
     BTSerial.write("1");}
  else {
     BTSerial.write("0");}

if (arret == false){
 switch (message){

case 97: //avant
  x = x + pas;
break;

case 98: //arrière
  x = x - pas;
break;

/*case 99: // droite
break;

case 100: // gauche
break;*/

case 101: // haut
  y = y + pas;
break;

case 102: //bas
  y = y - pas;
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

case 105: //attrape
  servopince.write(75);
break;

case 106: //lâche
  servopince.write(95); 
break;
  }

 if (alpha0 < alpha1){digitalWrite(M1, 0);
                      digitalWrite(E1,value);}        // sortir tige vérin bas
 else{digitalWrite(M1,1);
      digitalWrite(E1,value);}                        //rentrer tige vérin bas
      
 if (beta0 < beta1){digitalWrite(M2,0);
                    digitalWrite(E2,value);}        //sortir tige vérin haut
 else{digitalWrite(M2,1);
      digitalWrite(E2,value);}                       //rentrer  tige vérin haut
 
 }

else { x = a*(cos (alpha0*pi/180)- cos ((beta0 + alpha0)*pi/180)); 
       y = a*(sin(alpha0*pi/180)-sin((beta0 + alpha0)*pi/180));}



                                                             
if (message != 101 && message != 102 && message != 97 && message != 98){    //couper vérins
digitalWrite(E1,0);
digitalWrite(E2,0);}

servohorizon.write((alpha0 + beta0)*(100/127)-56.7);

if (digitalRead(2) == 1 or message == 107){arret = true;}
else{arret = false;} 

  delay(20);
}
