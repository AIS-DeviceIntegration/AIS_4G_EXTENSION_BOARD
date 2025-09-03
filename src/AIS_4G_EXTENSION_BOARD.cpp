#include <Arduino.h>
#include <AIS_4G_EXTENSION_BOARD.h>

ConfigExtension extConfig;

void AIS_4G_EXTENSION_BOARD::begin(ConfigExtension _extConfigs)
{

    Serial.println(("###### AIS_4G_EXTENSION_BOARD Library version: " + String(LIB_VERSION)).c_str());
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

bool AIS_4G_EXTENSION_BOARD::checkExtension()
{
    this->foundExtension = false;
    Wire.begin();
    for (byte addr = 0x01; addr < 0x7F; addr++)
    {
        Wire.beginTransmission(addr);
        if (Wire.endTransmission() == 0 && addr == 0x19)
        {
            this->foundExtension = true;
            
            break;
        }
    }
    Serial.println(F("====Check Extension available===="));
    Serial.println(this->foundExtension ? F("[✓] - Found Extension Board!!") : F("[x] - No Extension Board Found!!"));
    return this->foundExtension;
}
bool AIS_4G_EXTENSION_BOARD::isExtensionAvailable()
{
    return this->foundExtension;
}
