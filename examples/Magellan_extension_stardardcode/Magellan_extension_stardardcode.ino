#include <Arduino.h>
#include <MAGELLAN_SIM7600E_MQTT.h>
#include <AIS_4G_EXTENSION_BOARD.h>
#include <RS485.h>

MAGELLAN_SIM7600E_MQTT magel;
AIS_4G_EXTENSION_BOARD extBoard;
// dry 1600 wet 800 for normal connect if jump pin analog and digital together use dry 2000 wet 1750 R adjust left side
#define DRY_MILLIVOLT 2000       // please calibrate by read rawMillivolt on dry and wet for accuracy
#define WET_MILLIVOLT 1750        // please calibrate by read rawMillivolt on dry and wet for accuracy
unsigned long time_previous = 0; // previous time for using timer with millis()

void setup()
{
    Serial.begin(115200);
    RS485.begin(9600, SERIAL_8N1);
    extBoard.begin();                                             // initialize extension board
    extLightMeter.begin();                                        // initialize [BH1750]light meter sensor
    extSoilMoisture.begin(AIN::A1, WET_MILLIVOLT, DRY_MILLIVOLT); // initialize soilMoisture sensor connect on "A1" with value from calibrate dry, wet

    setting.endpoint = "device-entmagellan.ais.co.th";
    setting.clientBufferSize = defaultOTABuffer;
    magel.begin(setting);

    magel.getControl([](String key, String value)
                     {
                         Serial.println("Control incoming - [Key]:" + key + " [Value]" + value);
                         // Control turn ON OFF Relay1
                         if (key == "Relay1")
                         {
                             if (value == "1")
                             {
                                 extBoard.set(RELAY::CH1, HIGH); // set status ON OFF Relay Channel 1
                             }
                             else
                             {
                                 extBoard.set(RELAY::CH1, LOW); // set status ON OFF Relay Channel 1
                             }
                         }
                         // Control turn ON OFF Relay2
                         if (key == "Relay2")
                         {
                             if (value == "1")
                             {
                                 extBoard.set(RELAY::CH2, HIGH); // set status ON OFF Relay Channel 2
                             }
                             else
                             {
                                 extBoard.set(RELAY::CH2, LOW); // set status ON OFF Relay Channel 2
                             }
                         }
                         // Control turn ON OFF Relay3
                         if (key == "Relay3")
                         {
                             if (value == "1")
                             {
                                 extBoard.set(RELAY::CH3, HIGH); // set status ON OFF Relay Channel 3
                             }
                             else
                             {
                                 extBoard.set(RELAY::CH3, LOW); // set status ON OFF Relay Channel 3
                             }
                         }
                         // Control turn ON OFF Relay4
                         if (key == "Relay4")
                         {
                             if (value == "1")
                             {
                                 extBoard.set(RELAY::CH4, HIGH); // set status ON OFF Relay Channel 4
                             }
                             else
                             {
                                 extBoard.set(RELAY::CH4, LOW); // set status ON OFF Relay Channel 4
                             }
                         }
                         magel.control.ACK(key, value); // ACKNOWLEDGE Control back to magellan
                     });

    // sync output status on device turn off all to magellan
    magel.sensor.add("Relay1", 0);
    magel.sensor.add("Relay2", 0);
    magel.sensor.add("Relay3", 0);
    magel.sensor.add("Relay4", 0);
    magel.sensor.report();
}

void loop()
{
    magel.loop();
    magel.subscribes([]()
                     { magel.subscribe.control(PLAINTEXT); });

    // read and update value sensor every 15 seconds
    magel.interval(15, []()
                   {
        //read from RS485 XY MD02
        long temp_int16 = RS485.inputRegisterRead(1, 1);
        delay(50);
        long humi_int16 = RS485.inputRegisterRead(1, 2);
        float temp_float = temp_int16 / 10.0;  //buffer read value RS485 XY MD02
        float humi_float = humi_int16 / 10.0; //buffer read value RS485 XY MD02

        float LightMeter = extLightMeter.readLight();
        float SoilMoisture = extSoilMoisture.readMoisturePercent();
        float BoardTemp = magel.builtInSensor.readTemperature();
        float BoardHumid = magel.builtInSensor.readHumidity();
        if (magel.gps.available())
        {
            String Location = magel.gps.readLocation(); // "lat,lng"
            magel.sensor.add("GPS", Location);
        }
        magel.sensor.add("Light", LightMeter);
        magel.sensor.add("SoilMoisture", SoilMoisture);
        magel.sensor.add("BoardTemp", BoardTemp);
        magel.sensor.add("BoardHumid", BoardHumid);
        magel.sensor.add("RS485Temp", temp_float);
        magel.sensor.add("RS485Humid", humi_float);
        magel.sensor.report(); });

    // read and update status relay every 5 minutes to magellan
    if (millis() - time_previous > 300000)
    {
        time_previous = millis(); // update time

        int statusRelay1 = extBoard.read(RELAY::CH1); // read status Relay Channel 1
        int statusRelay2 = extBoard.read(RELAY::CH2); // read status Relay Channel 2
        int statusRelay3 = extBoard.read(RELAY::CH3); // read status Relay Channel 3
        int statusRelay4 = extBoard.read(RELAY::CH4); // read status Relay Channel 4
        magel.sensor.add("Relay1", statusRelay1);
        magel.sensor.add("Relay2", statusRelay2);
        magel.sensor.add("Relay3", statusRelay3);
        magel.sensor.add("Relay4", statusRelay4);
        magel.sensor.report();
    }
}