int anglP = 270;
int i=0;
int somme=0;

void setup() {
pinMode (A0,INPUT);     //alpha
pinMode (8,INPUT);
Serial.begin (9600);



}

void loop() {

  i=i+1;
  somme =somme +analogRead (A0);
  Serial.println (analogRead(A0));   //(analogRead (A0)*anglP/1024);
  delay(50);
  
}
