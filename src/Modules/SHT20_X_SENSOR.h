#ifndef SHT20_X_SENSOR_h
#define SHT20_X_SENSOR_h
#include <Arduino.h>
#include "IncludeLibs.h"

class SHT20_X_SENSOR : private SHT2x
{
private:
    SHT2x *_sht2x;

public:
    SHT20_X_SENSOR()
    {
        _sht2x = new SHT2x();
    }
    void begin();
    float readTemperature();
    float readHumidity();
    bool heatSensor(bool enable);
    bool isSensorHeatOn();            // is the sensor still heating up?
    bool setHeaterLv(uint8_t level);  // level = 0..15
    bool getHeaterLv(uint8_t &level); // 0..15
};
extern SHT20_X_SENSOR extSHT20;
#endif