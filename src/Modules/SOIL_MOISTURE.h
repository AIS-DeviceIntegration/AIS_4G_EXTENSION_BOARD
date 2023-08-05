#ifndef SOIL_MOISTURE_h
#define SOIL_MOISTURE_h
//Capacitive Soil Moisture Sensor V1.2
#include <Arduino.h>
#include "IncludeLibs.h"
#include "../ExtBoardGPIO.h"

class SOIL_MOISTURE
{
private:
    int _analogPin = -1;
    int _wet_millivolt = 3620;
    int _dry_millivolt = 1680;
public:
    SOIL_MOISTURE(){};
    void begin(AIN anlogINPUT, int WET_MILLIVOLT, int DRY_MILLIVOLT);
    void begin(AIN anlogINPUT);
    void calibrateSensor(int WET_MILLIVOLT, int DRY_MILLIVOLT);
    float readRawMillivolt();
    float readMoisetureLevel();
};
extern SOIL_MOISTURE extSoilMoisture;

#endif