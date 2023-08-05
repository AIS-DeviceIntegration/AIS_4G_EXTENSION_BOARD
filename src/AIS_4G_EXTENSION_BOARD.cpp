#include <Arduino.h>
#include <AIS_4G_EXTENSION_BOARD.h>

ConfigExtension extConfig;

void AIS_4G_EXTENSION_BOARD::begin(ConfigExtension _extConfigs)
{
    if (_extConfigs.IOExpander)
    {
        usingIOexpand = true;
        IO_expand.begin();
    }

    if (_extConfigs.RTCextension)
    {
        usingRTC = true;
        extRTC.begin();
    }
}

void AIS_4G_EXTENSION_BOARD::setTime(Time times)
{
    extRTC.setTime(times);
}
Time AIS_4G_EXTENSION_BOARD::getTime()
{
    return extRTC.getTime();
}
String AIS_4G_EXTENSION_BOARD::getDateTimeString()
{
    return extRTC.getDateTimeString();
}
