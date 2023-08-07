#ifndef SHT20_SENSOR_h
#define SHT20_SENSOR_h
#include <Arduino.h>
#include "IncludeLibs.h"

class SHT20_SENSOR : private DFRobot_SHT20
{
private:
    DFRobot_SHT20 *sht20;
    // (&Wire, SHT20_I2C_ADDR);
    // SHT2x *_sht2x;

public:
    SHT20_SENSOR()
    {
        sht20 = new DFRobot_SHT20(&Wire, SHT20_I2C_ADDR);
    }
    void begin();
    float readTemperature();
    float readHumidity();
};
extern SHT20_SENSOR extSHT20;
#endif