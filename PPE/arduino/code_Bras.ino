
// déclarer les pins

void setup() {
 
 Serial.begin(9600);
 
delay(2000);
Serial.write(0xAA);
Serial.write(0x37);

}

void loop() {

  Serial.write(0xAA);
  Serial.write(0x23);
  while (Serial.read() != 0x31) 
        {delay(100);}

  Serial.write(0x22);
  switch (Serial.read()){
     case 0x24:
       mouvement();
     case 0x25:
       fonction();      }
     
}

void mouvement(){
  
}

void fonction(){
  
}
