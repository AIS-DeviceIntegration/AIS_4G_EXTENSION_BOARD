#include <Arduino.h>
#include <AIS_4G_EXTENSION_BOARD.h>

#include <RTClib.h> //require install RTClib library adafruit/RTClib@^2.1.4
#include <SPI.h> //require include RTClib library adafruit/RTClib@^2.1.4 
#include <Adafruit_I2CDevice.h> //install include RTClib library adafruit/RTClib@^2.1.4

AIS_4G_EXTENSION_BOARD extBoard;

void setup()
{
    Serial.begin(115200);
    extBoard.begin(); // initialize extBoardension board

    //Upload this code to the board to sync the time once. then time RTC uptodate comment this code and upload again
    DateTime date = DateTime(F(__DATE__), F(__TIME__)); //Get time from PC//require install RTClib library adafruit/RTClib@^2.1.4
    Time timeset;
    timeset.year = date.year();     // set year set only last 2 digits
    timeset.month = date.month();   // set month
    timeset.day = date.day();       // set day
    timeset.hour = date.hour();     // set hour
    timeset.minute = date.minute(); // set minute
    timeset.second = date.second(); // set second
    extBoard.setTime(timeset);

    // set time to to 30/7/2023 17:33:0 (Sync Manual)
    // Time timeset;
    // timeset.year = 23;   // set year set only last 2 digits
    // timeset.month = 7;   // set month
    // timeset.day = 30;    // set day
    // timeset.hour = 17;   // set hour
    // timeset.minute = 33; // set minute
    // timeset.second = 0;  // set second
    // extBoard.setTime(timeset)
}

void loop()
{
    String dateTimeString = extBoard.getDateTimeString(); // format date time string "dd/mm/yyyy HH:MM:SS:SS"
    Serial.print("DateTime: ");
    Serial.println(dateTimeString);

    Time times = extBoard.getTime();
    Serial.print("Day: ");
    Serial.println(times.day);
    Serial.print("Month: ");
    Serial.println(times.month);
    Serial.print("Year: ");
    Serial.println(times.year);
    Serial.print("Hour: ");
    Serial.println(times.hour);
    Serial.print("Minute: ");
    Serial.println(times.minute);
    Serial.print("Second: ");
    Serial.println(times.second);
    delay(1000);
}