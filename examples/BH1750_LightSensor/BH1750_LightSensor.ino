#include <Arduino.h>
#include <AIS_4G_EXTENSION_BOARD.h>

AIS_4G_EXTENSION_BOARD extBoard;

void setup()
{
    Serial.begin(115200);
    extLightMeter.begin();
}

void loop()
{
    Serial.print("BH1750 Light: ");
    Serial.print(extLightMeter.readLight());
    Serial.println(" Lux.");
    delay(2000);
}