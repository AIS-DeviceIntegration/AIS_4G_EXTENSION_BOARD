#include <Arduino.h>
#include <AIS_4G_EXTENSION_BOARD.h>

AIS_4G_EXTENSION_BOARD extBoard;

void setup()
{
    Serial.begin(115200);
    extBoard.begin(); // initialize extBoardension board
}

void loop()
{
    // Turn ON Relay
    extBoard.set(RELAY::CH1, HIGH);
    delay(1000);
    extBoard.set(RELAY::CH2, HIGH);
    delay(1000);
    extBoard.set(RELAY::CH3, HIGH);
    delay(1000);
    extBoard.set(RELAY::CH4, HIGH);
    delay(1000);
   
    Serial.print("RELAY ON ALL");
    Serial.print("RELAY1: ");
    Serial.println(extBoard.read(RELAY::CH1));
    Serial.print("RELAY2: ");
    Serial.println(extBoard.read(RELAY::CH2));
    Serial.print("RELAY3: ");
    Serial.println(extBoard.read(RELAY::CH3));
    Serial.print("RELAY4: ");
    Serial.println(extBoard.read(RELAY::CH4));

    // Turn OFF Relay
    extBoard.set(RELAY::CH1, LOW);
    delay(1000);
    extBoard.set(RELAY::CH2, LOW);
    delay(1000);
    extBoard.set(RELAY::CH3, LOW);
    delay(1000);
    extBoard.set(RELAY::CH4, LOW);
    delay(1000);
    
    Serial.print("RELAY OFF ALL");
    Serial.print("RELAY1: ");
    Serial.println(extBoard.read(RELAY::CH1));
    Serial.print("RELAY2: ");
    Serial.println(extBoard.read(RELAY::CH2));
    Serial.print("RELAY3: ");
    Serial.println(extBoard.read(RELAY::CH3));
    Serial.print("RELAY4: ");
    Serial.println(extBoard.read(RELAY::CH4));
}