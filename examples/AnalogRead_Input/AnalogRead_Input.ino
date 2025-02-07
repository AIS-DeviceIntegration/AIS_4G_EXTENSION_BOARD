#include <Arduino.h>
#include <AIS_4G_EXTENSION_BOARD.h>
AIS_4G_EXTENSION_BOARD extBoard;

void setup()
{
    Serial.begin(115200);
    extBoard.begin();
}

void loop()
{
    // {1} Read analog from A1 and A2 on extension board (uncomment to use this)
    int analogA1 = extBoard.read(AIN::A1);
    Serial.print("AnalogA1: ");
    Serial.print(analogA1);
    Serial.print("  ");

    int analogA2 = extBoard.read(AIN::A2);
    Serial.print("AnalogA2: ");
    Serial.println(analogA2);
    delay(500);

    // {2} Get GPIO number from enum (uncomment to use this)
    // int analogA1 = analogRead(extBoard.getPinAIN(AIN::A1));
    // Serial.print("AnalogA1: ");
    // Serial.print(analogA1);
    // Serial.print("  ");
    // int analogA2 = analogRead(extBoard.getPinAIN(AIN::A2));
    // Serial.print("AnalogA2: ");
    // Serial.println(analogA2);
    // delay(500);

    // {3} Directly read the analog value from the pin define (uncomment to use this)
    // int analogA1 = analogRead(A1_PIN);
    // Serial.print("AnalogA1: ");
    // Serial.print(analogA1);
    // Serial.print("  ");
    // int analogA2 = analogRead(A2_PIN);
    // Serial.print("AnalogA2: ");
    // Serial.println(analogA2);
    // delay(500);
}