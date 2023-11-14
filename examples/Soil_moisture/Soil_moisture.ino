#include <Arduino.h>
#include <AIS_4G_EXTENSION_BOARD.h>

AIS_4G_EXTENSION_BOARD extBoard;

#define DRY_millivolt 1600 // please calibrate by read rawMillivolt on dry and wet for accuracy
#define WET_millivolt 800  // please calibrate by read rawMillivolt on dry and wet for accuracy
void setup()
{
    Serial.begin(115200);
    extSoilMoisture.begin(AIN::A1, WET_millivolt, DRY_millivolt); // select Analog "A1" to read Sensor Soil Moisture
}

void loop()
{
    Serial.print("Soil Moisture Level: ");
    Serial.println(extSoilMoisture.readMoistureLevel(), 1);
    Serial.print("Soil Moisture Percent: ");
    Serial.print(extSoilMoisture.readMoisturePercent());
    Serial.println(" v%");
    delay(2000);
}