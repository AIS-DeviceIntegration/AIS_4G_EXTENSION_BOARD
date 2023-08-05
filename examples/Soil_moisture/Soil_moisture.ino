#include <Arduino.h>
#include <AIS_4G_EXTENSION_BOARD.h>

AIS_4G_EXTENSION_BOARD extBoard;

#define DRY_millivolt 2038 // please calibrate by read rawMillivolt on dry and wet for accuracy 
#define WET_millivolt 1675 // please calibrate by read rawMillivolt on dry and wet for accuracy
void setup()
{
    Serial.begin(115200);
    extSoilMoisture.begin(AIN::A1, WET_millivolt, DRY_millivolt); // select Analog "A1" to read Sensor Soil Moisture
}

void loop()
{
    Serial.print("Soil Moisture Level: ");
    Serial.println(extSoilMoisture.readMoisetureLevel(), 1);
    delay(2000);
}