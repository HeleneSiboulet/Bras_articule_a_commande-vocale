void setup() {
  pinMode (2,OUTPUT);
  Serial.begin (115200);

}

void loop() {
  
  while (Serial.available() == 0) {Serial.println("je reçois rien"); delay(500);};
  char b = Serial.read ();
  if(b == 1){
    digitalWrite (2,1); }
  if(b == 0){
    digitalWrite (2,0); }
  Serial.println(b);
  
delay (500);
}
