#include <Arduino.h>
#include <AIS_4G_EXTENSION_BOARD.h>

AIS_4G_EXTENSION_BOARD extBoard;

void setup()
{
    Serial.begin(115200);
    extSHT20.begin();
}

void loop()
{
    Serial.print("SHT20 Temperature: ");
    Serial.println(extSHT20.readTemperature());
    Serial.print("SHT20 Humidity: ");
    Serial.println(extSHT20.readHumidity());
    delay(2000);
}