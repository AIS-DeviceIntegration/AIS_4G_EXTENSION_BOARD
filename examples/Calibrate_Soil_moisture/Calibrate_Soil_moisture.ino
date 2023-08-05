#include <Arduino.h>
#include <AIS_4G_EXTENSION_BOARD.h>

AIS_4G_EXTENSION_BOARD extBoard;
void setup()
{
    Serial.begin(115200);
    extSoilMoisture.begin(AIN::A1); // select Analog "A1" to read Sensor Soil Moisture
}

void loop()
{
    Serial.print("Read Raw millivolt: ");
    // read raw millivolt on Dry and Wet and record value config on begin
    //such as extSoilMoisture.begin(AIN::A1, WET_millivolt, DRY_millivolt); // select Analog "A1" to read
    Serial.println(extSoilMoisture.readRawMillivolt()); 
    delay(2000);
}