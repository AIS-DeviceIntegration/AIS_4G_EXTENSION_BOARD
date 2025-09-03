#ifndef AIS_4G_EXTENSION_BOARD_h
#define AIS_4G_EXTENSION_BOARD_h

#include <Arduino.h>
#include <ExtBoardGPIO.h>
#include <ExternalModules.h>
#include <Wire.h>

#define LIB_Major 1
#define LIB_Minor 2
#define LIB_Feature 0
#define LIB_VERSION String(LIB_Major) + "." + String(LIB_Minor) + "." + String(LIB_Feature)

struct ConfigExtension
{
    bool IOExpander = true;
    bool RTCextension = true;
};
extern ConfigExtension extConfig;
class AIS_4G_EXTENSION_BOARD : public IO_EXPANDER
{
public:
    AIS_4G_EXTENSION_BOARD()
    {
        this->foundExtension = false;
    };
    void begin(ConfigExtension _extConfigs = extConfig);
    void setTime(Time times);
    Time getTime();
    String getDateTimeString();
    bool checkExtension();
    bool isExtensionAvailable();

private:
    IO_EXPANDER IO_expand;
    bool usingRTC = false;
    bool usingIOexpand = false;
    bool foundExtension = false;
};

#endif