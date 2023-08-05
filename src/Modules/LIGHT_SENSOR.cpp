
#include <Arduino.h>
#include "LIGHT_SENSOR.h"

LIGHT_SENSOR::LIGHT_SENSOR(uint8_t address)
{
    this->_address = address;
    _lightmeter = new BH1750(this->_address);
}

bool LIGHT_SENSOR::isAvailable(bool maxWait)
{
    return _lightmeter->measurementReady(maxWait);
}

void LIGHT_SENSOR::begin(BH1750::Mode mode)
{
    Wire.begin();
    if (_lightmeter->begin(mode))
    {
        Serial.println(F("[Light Sensor]BH1750 Advanced begin"));
    }
    else
    {
        Serial.println(F("[Light Sensor]BH1750 Error initialising"));
    }
}

float LIGHT_SENSOR::readLight()
{
    float val = -1;
    if (_lightmeter->measurementReady())
    {
        val = _lightmeter->readLightLevel();
    }
    return val;
}

bool LIGHT_SENSOR::configure(BH1750::Mode mode)
{
    return _lightmeter->configure(mode);
}