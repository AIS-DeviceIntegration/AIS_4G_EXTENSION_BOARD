#ifndef RTCMODULE_PCF8563_h
#define RTCMODULE_PCF8563_h
#include <Arduino.h>
#include "IncludeLibs.h"
#define rtc_verMajor 1
#define rtc_verMinor 0
#define rtc_verRevision 0

class RTC_PCF8563 : public PCF8563
{
public:
    RTC_PCF8563();
    void begin();
    void setTime(Time times);
    Time getTime();
    tm get_tm_Time();
    String getDateTimeString();
private:
    PCF8563 _rtc;
protected:
};
extern RTC_PCF8563 extRTC;

#endif