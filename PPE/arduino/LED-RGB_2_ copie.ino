int receive = 0;

void setup() {
  Serial.begin(9600);
  pinMode (3,OUTPUT);
}

void loop() {
  if (Serial.available() > 0){receive = Serial.read();}
  if (receive == 1){digitalWrite(3,1);}
  else{digitalWrite(3,0);}
  Serial.print (receive);
  delay(50);
}
