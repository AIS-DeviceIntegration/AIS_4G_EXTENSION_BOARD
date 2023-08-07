#ifndef INCLUDELIBS_h
#define INCLUDELIBS_h

#include <Arduino.h>
#include "Wire.h"
//Relay on extension
enum class RELAY
{
    CH1,
    CH2,
    CH3,
    CH4,
};

// DigitalIN DIN Digital input on expander GPIO
enum class DIN
{
    D1,
    D2,
};

// AnalogIN On board
enum class AIN
{
    A1,
    A2,
};
// Digital_IO on board can be in out
enum class DIGITAL
{
    D3,
};


#include "../Includes/BH1750/src/BH1750.h"
#include "../Includes/PCA9557-arduino/src/PCA9557.h"
#include "../Includes/PCF8563-Arduino-Library-master/src/PCF8563.h"
#include "../Includes/SHT2x/SHT2x.h"
#include "../Includes/DFRobot_SHT20/DFRobot_SHT20.h"

#endif