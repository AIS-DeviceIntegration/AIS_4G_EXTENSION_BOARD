
#include "SOIL_MOISTURE.h"

float mathCamp(float _input, float _min, float _max){
    return constrain(_input, _min, _max);
}

void SOIL_MOISTURE::calibrateSensor(int WET_MILLIVOLT, int DRY_MILLIVOLT)
{
    this->_dry_millivolt = DRY_MILLIVOLT;
    this->_wet_millivolt = WET_MILLIVOLT;
}

void SOIL_MOISTURE::begin(AIN anlogINPUT, int WET_MILLIVOLT, int DRY_MILLIVOLT)
{
    switch (anlogINPUT)
    {
    case AIN::A1:
        _analogPin = A1_PIN;
        break;
    case AIN::A2:
        _analogPin = A2_PIN;
        break;
    default:
        break;
    }
    calibrateSensor(WET_MILLIVOLT, DRY_MILLIVOLT);
}

void SOIL_MOISTURE::begin(AIN anlogINPUT)
{
    switch (anlogINPUT)
    {
    case AIN::A1:
        _analogPin = A1_PIN;
        break;
    case AIN::A2:
        _analogPin = A2_PIN;
        break;
    default:
        break;
    }
}

float SOIL_MOISTURE::readRawMillivolt()
{
    return (float)analogRead(this->_analogPin);
}

float SOIL_MOISTURE::readMoisetureLevel()
{
    int rawAnalog = readRawMillivolt();
    float moistureLevel = map(rawAnalog, this->_dry_millivolt, this->_wet_millivolt, 0, 100) / 10.0;
    float result = mathCamp(moistureLevel, 0.0f, 10.0f);
    return result;
}
