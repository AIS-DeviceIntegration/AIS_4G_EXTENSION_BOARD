#include <Arduino.h>
#include "SHT20_X_SENSOR.h"

void SHT20_X_SENSOR::begin()
{
    this->_sht2x->begin();
    uint8_t stat = _sht2x->getStatus();
}
float SHT20_X_SENSOR::readTemperature()
{
    this->_sht2x->read();
    return this->_sht2x->getTemperature();
}

float SHT20_X_SENSOR::readHumidity()
{
    this->_sht2x->read();
    return this->_sht2x->getHumidity();
}

bool SHT20_X_SENSOR::heatSensor(bool enable)
{
    bool status = false;
    if (enable)
    {
       status = this->_sht2x->heatOn();
    }
    else
    {
       status = this->_sht2x->heatOff();
    }
    return  status;
}

bool SHT20_X_SENSOR::isSensorHeatOn()
{
    return this->_sht2x->isHeaterOn();
}

bool SHT20_X_SENSOR::setHeaterLv(uint8_t level)
{
    return this->_sht2x->setHeaterLevel(level);
}

bool SHT20_X_SENSOR::getHeaterLv(uint8_t &level)
{
    return this->_sht2x->getHeaterLevel(level);
}