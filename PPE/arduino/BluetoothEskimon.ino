
#include <SoftwareSerial.h>

SoftwareSerial mavoieserie(11, 10); // (RX, TX) (pin Rx BT, pin Tx BT)

void setup()
{
    // Ouvre la voie série avec l'ordinateur
    Serial.begin(9600);
    // Ouvre la voie série avec le module BT
    mavoieserie.begin(9600);
}

void loop() // run over and over
{
    if (mavoieserie.available()) {
        Serial.print(mavoieserie.read());
        Serial.println("qqc");
    }
    else {Serial.println("rien");}
    delay(50);
}
