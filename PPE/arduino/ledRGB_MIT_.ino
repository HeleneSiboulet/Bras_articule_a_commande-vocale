 #include <SoftwareSerial.h>

SoftwareSerial BTSerial (10,11);    // TX : 10    RX: 11

void setup() {

  Serial.begin (9600);
  BTSerial.begin (9600);
  pinMode(2,OUTPUT);
  pinMode (8,INPUT);
 // pinMode (11, INPUT);
 //pinMode (10, OUTPUT);
  
}

void loop() {


if (digitalRead (8) == 1){
  BTSerial.write("1");
  //Serial.println("oui");
  }
  
if (digitalRead (8) == 0){
  BTSerial.write("0");
  //Serial.println("oui");
  }
  delay(50);

  
 Serial.println(BTSerial.read());
  //Serial.println(BTSerial.available());

if (BTSerial.read()==0){
  digitalWrite(2,0);}
if (BTSerial.read()==1){
  digitalWrite(2,0);}

  
 /*String message = BTSerial.readString();
Serial.println (message) ;
if (message ==""){Serial.println("rien");}
delay(10);

if (message == "a"){
  digitalWrite(2,HIGH);}

if (message == "e"){
  digitalWrite(2,LOW);}*/
}
