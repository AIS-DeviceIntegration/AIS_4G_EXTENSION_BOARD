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
    // Read old version
    // long temp_int16 = RS485.inputRegisterRead(1, 1);
    // delay(50);
    // long humi_int16 = RS485.inputRegisterRead(1, 2);
    //     Serial.print("Temperature: ");
    // Serial.print(temp_float);
    // Serial.print(" *C\t");
    // Serial.print("Humidity: ");
    // Serial.print(humi_float);
    // Serial.println(" %RH");

    // Read new version
    uint16_t values[2]; // temp[0], humidity[1]
    int n = RS485.inputRegisterReadU16Array(1, 1, values, 2);
    // Device ID = 1, start address = 1, quantity = 2
    float temp_float = -1, humi_float = -1; // -1 meaning can't read value from sensor
    if (n == 2)
    {
        temp_float = values[0] / 10.0;
        humi_float = values[1] / 10.0;

        Serial.print("Temperature: ");
        Serial.print(temp_float);
        Serial.println(" *C");

        Serial.print("Humidity: ");
        Serial.print(humi_float);
        Serial.println(" %");
    }
    else
    {
        Serial.println("XY_MDO2 Read failed");
    }

    delay(2000);
}