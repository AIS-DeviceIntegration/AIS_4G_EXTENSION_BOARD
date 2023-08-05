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
    bool statusD1 = extBoard.read(DIN::D1); // connect power (range 3.3v - 12v) to socket D1
    Serial.print("Status D1: ");
    Serial.println(statusD1);
    bool statusD2 = extBoard.read(DIN::D2); // connect power (range 3.3v - 12v) to socket D2
    Serial.print("Status D2: ");
    Serial.println(statusD2);
    delay(2000);
}