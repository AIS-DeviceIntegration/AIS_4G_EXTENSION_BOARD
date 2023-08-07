#include <Arduino.h>
#include <AIS_4G_EXTENSION_BOARD.h>

AIS_4G_EXTENSION_BOARD extBoard;

void setup()
{
    Serial.begin(115200);
    extSHT20X.begin();
}

void loop()
{
    Serial.print("SHT20-X Temperature: ");
    Serial.println(extSHT20X.readTemperature());
    Serial.print("SHT20-X Humidity: ");
    Serial.println(extSHT20X.readHumidity());
    delay(2000);
}