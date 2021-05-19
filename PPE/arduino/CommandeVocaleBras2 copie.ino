 #include <SoftwareSerial.h>

int message = 0;
double x;
double y;
int alpha0;
double alpha1;
double alphaMax;
double alphaMin;
int beta0;
double beta1;
double betaMax;
double betaMin;

double a = 350;
double anglP = 200;
bool arret;
int pas = 0,1;



SoftwareSerial BTSerial (10,11);    // TX : 10    RX: 11

void setup() {
  
  Serial.begin (9600);
 BTSerial.begin (9600);

  pinMode (8,INPUT);

x=a*(cos (alpha0)-cos (beta0 + alpha0));
y=a*(sin(alpha0)-sin (beta0 + alpha0));
  
}

void loop() {

  
  if (BTSerial.available() > 0 ){message = (BTSerial.read());}
  Serial.println (message);

  if (digitalRead (8) == 1) {
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
  y = y+pas;
break;

case 102: //bas
  y=y-pas;
break;

case 105: //attrape
  analogWrite (13,45);
break;

case 106: //lâche
  analogWrite (13,120);
break;

case 107: //stop
break;

 }}
else {x=a*(cos (alpha0)-cos (beta0 + alpha0));
      y=a*(sin(alpha0)-sin (beta0 + alpha0));}

// if (message != 99 && message != 100){} // couper le moteur
 
alpha0 = analogRead (A0)*anglP/1024;
beta0 = analogRead (A1)*anglP/1024;

alpha1 = ( acos (sqrt(pow(x,2) + pow(y,2))/(2*a)) + acos (x/(sqrt(pow(x,2) + pow(y,2))) ));
beta1 =  (180 - 2* acos(sqrt(pow(x,2) + pow(y,2))/2*a));

if (arret == false){

if (betaMin < beta1  && beta1 < betaMax){if (beta0 < beta1){digitalWrite(4,0);    //sortir verin du haut
                                                            digitalWrite(9,1);}
                                                       else{digitalWrite(4,1);    // rentrer le vérin haut
                                                            digitalWrite(9,1);}}
                                          
if (alphaMin < alpha1  && alpha1 < alphaMax){if (alpha0 < alpha1){digitalWrite(7,1);        //rentrer verin du bas
                                                                  digitalWrite(6,1);}
                                                             else{digitalWrite(7,0);   // sortir vérin bas
                                                                  digitalWrite(6,1);}}}
                                                             
if (message != 101 && message != 102 && message != 97 && message != 98){
digitalWrite(6,0);
digitalWrite(7,0);
digitalWrite(4,0);
digitalWrite(9,0);} 




if (digitalRead(8) == 1 or message == 107){arret = true;}
else{arret = false;} 

analogWrite(12,(alpha0+beta0)*(255/(180)));    // vérifier l'angle du servo

  delay(20);
}
