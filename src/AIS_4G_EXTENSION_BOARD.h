#ifndef AIS_4G_EXTENSION_BOARD_h
#define AIS_4G_EXTENSION_BOARD_h

#include <Arduino.h>
// #include "Modules/IncludeLibs.h"
#include <ExtBoardGPIO.h>
#include <ExternalModules.h>

struct ConfigExtension
{
    bool IOExpander = true;
    bool RTCextension = true;
};
extern ConfigExtension extConfig;
class AIS_4G_EXTENSION_BOARD : public IO_EXPANDER
{
public:
    AIS_4G_EXTENSION_BOARD(){};
    void begin(ConfigExtension _extConfigs = extConfig);
    void setTime(Time times);
    Time getTime();
    String getDateTimeString();
private:
    IO_EXPANDER IO_expand;
    bool usingRTC = false;
    bool usingIOexpand = false;
};

#endif