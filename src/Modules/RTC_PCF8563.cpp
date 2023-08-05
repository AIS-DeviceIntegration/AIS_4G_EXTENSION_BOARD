
#include <Arduino.h>
#include "RTC_PCF8563.h"

RTC_PCF8563::RTC_PCF8563()
{
}

void RTC_PCF8563::begin()
{
    Wire.begin();
    _rtc.init();
    _rtc.stopClock();  // stop the clock
    _rtc.startClock(); // start the clock
}

void RTC_PCF8563::setTime(Time _time)
{
    _rtc.setDay(_time.day);
    _rtc.setMonth(_time.month);
    _rtc.setYear(_time.year);
    _rtc.setHour(_time.hour);
    _rtc.setMinut(_time.minute);
    _rtc.setSecond(_time.second);
}

Time RTC_PCF8563::getTime()
{
    return _rtc.getTime();
}

String RTC_PCF8563::getDateTimeString()
{
    Time t = _rtc.getTime();
    char buffer[100];
    sprintf(buffer, "%02d/%02d/20%d %02d:%02d:%02d", t.day, t.month, t.year, t.hour, t.minute, t.second);
    String dateTime = String(buffer);
    return dateTime;
}

tm RTC_PCF8563::get_tm_Time()
{
    tm timeinfo;
    Time timeData = getTime();
    timeinfo.tm_year = timeData.year + 100; // Assuming year 2000 as the starting point (2000 + 100 = 2100)
    timeinfo.tm_mon = timeData.month - 1;   // Months in tm struct are zero-based (0 to 11)
    timeinfo.tm_mday = timeData.day;
    timeinfo.tm_wday = timeData.weekday;
    timeinfo.tm_hour = timeData.hour;
    timeinfo.tm_min = timeData.minute;
    timeinfo.tm_sec = timeData.second;

    // Some fields are not available in the Time struct, so we make assumptions
    timeinfo.tm_isdst = -1; // Assume daylight saving time is not known (-1)

    return timeinfo;
}