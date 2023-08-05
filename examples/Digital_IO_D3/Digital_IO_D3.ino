#include <Arduino.h>
#include <AIS_4G_EXTENSION_BOARD.h>

AIS_4G_EXTENSION_BOARD extBoard;
void setup()
{
    Serial.begin(115200);
    extBoard.begin();
    extBoard.setMode(DIGITAL::D3, OUTPUT); //set D3 pinMode can be "INPUT" and "OUTPUT"
}

void loop()
{
    //turn on D3
    extBoard.set(DIGITAL::D3, HIGH); //digitalWrite D3 HIGH
    bool D3_status = extBoard.read(DIGITAL::D3); //read D3 status
    Serial.print("D3 Status: "); 
    Serial.println(D3_status);
    delay(1000);
    
    //turn off D3
    extBoard.set(DIGITAL::D3, LOW); //digitalWrite D3 HIGH
    D3_status = extBoard.read(DIGITAL::D3); //read D3 status
    Serial.print("D3 Status: "); 
    Serial.println(D3_status);
    delay(1000);
}