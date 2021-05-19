void setup() {
  pinMode (2,OUTPUT); //rouge
  pinMode (3,OUTPUT); //bleu
  pinMode (4,OUTPUT); //vert
}

void loop() {
   digitalWrite (2,1);
   delay (100);
   digitalWrite (2,0);
   delay (500);
   
}
