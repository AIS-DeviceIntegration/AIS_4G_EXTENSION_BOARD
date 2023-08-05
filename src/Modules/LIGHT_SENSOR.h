#ifndef LIGHT_SENSOR_h
#define LIGHT_SENSOR_h
#include <Arduino.h>
#include "IncludeLibs.h"
#define LightSensor_verMajor 1
#define LightSensor_verMinor 0
#define LightSensor_verRevision 0

class LIGHT_SENSOR : private BH1750
{
public:
    LIGHT_SENSOR(uint8_t address = 0x23);
    void begin(BH1750::Mode mode = BH1750::CONTINUOUS_HIGH_RES_MODE);
    float readLight();
    bool configure(Mode mode);
    bool isAvailable(bool maxWait = false);
private:
    uint8_t _address;
    BH1750 *_lightmeter;
};
extern LIGHT_SENSOR extLightMeter;
#endif