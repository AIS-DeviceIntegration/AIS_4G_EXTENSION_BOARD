#include <Arduino.h>
#include <AIS_4G_EXTENSION_BOARD.h>

AIS_4G_EXTENSION_BOARD extBoard;

void setup()
{
    Serial.begin(115200);
    extBoard.begin(); // initialize extBoardension board

    // set time to to 30/7/2023 17:33:0
    /*
    Time timeset;
    timeset.year = 23;   // set year set only last 2 digits
    timeset.month = 7;   // set month
    timeset.day = 30;    // set day
    timeset.hour = 17;   // set hour
    timeset.minute = 33; // set minute
    timeset.second = 0;  // set second
    extBoard.setTime(timeset)
    */
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