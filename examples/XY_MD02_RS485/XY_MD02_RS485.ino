#include <Arduino.h>
#include <RS485.h> //required libraries AIS_IoT_4G

unsigned long time_previous = 0; // previous time for using timer with millis()
void setup()
{
    RS485.begin(9600, SERIAL_8N1);
    Serial.begin(115200);
}
void loop()
{
    long temp_int16 = RS485.inputRegisterRead(1, 1);
    delay(50);
    long humi_int16 = RS485.inputRegisterRead(1, 2);

    float temp_float = temp_int16 / 10.0;
    float humi_float = humi_int16 / 10.0;

    Serial.print("Temperature: ");
    Serial.print(temp_float);
    Serial.print(" *C\t");
    Serial.print("Humidity: ");
    Serial.print(humi_float);
    Serial.println(" %RH");
    delay(2000);
}