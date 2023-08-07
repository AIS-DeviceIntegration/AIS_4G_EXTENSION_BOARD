#include <Arduino.h>
#include "SHT20_SENSOR.h"

void SHT20_SENSOR::begin()
{
    Wire.begin();
    this->sht20->initSHT20();
}
float SHT20_SENSOR::readTemperature()
{
    return this->sht20->readTemperature();
}

float SHT20_SENSOR::readHumidity()
{
    return this->sht20->readHumidity();
}