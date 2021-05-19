void setup () {
pinMode(3,OUTPUT);
}

void loop() {
delay(300);
digitalWrite(3,HIGH);
delay(300);
digitalWrite(3,LOW);
}