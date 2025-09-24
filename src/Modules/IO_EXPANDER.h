#ifndef IO_EXPANDER_h
#define IO_EXPANDER_h
#include <Arduino.h>
#include "IncludeLibs.h"
#include "../ExtBoardGPIO.h"
#define IO_Ex_verMajor 1
#define IO_Ex_verMinor 1
#define IO_Ex_verRevision 0

class IO_EXPANDER : private PCA9557
{
public:
    IO_EXPANDER(uint8_t address, TwoWire *bus);
    IO_EXPANDER();
    bool read(RELAY RelayChannel);
    bool read(DIN digitalINPUT);
    void set(RELAY RelayChannel, int value);
    void set(AIN analogIO, int value);
    void set(DIGITAL digitalIO, int value);
    uint16_t read(AIN analogINPUT);
    bool read(DIGITAL digitalIO);
    void setMode(DIGITAL digitalIO, int mode);
    void begin();
    
    // 1.1.0
    int getPinAIN(AIN analogINPUT);
    int getPinDIO(DIGITAL digitalIO);
    int getPinDIN(DIN digitalINPUT);

    // 1.2.1
    bool read(LCD lcdIO);
    void set(LCD lcdIO, int value);
    int getPinLCD(LCD lcd);

private:
    PCA9557 *_ext;
protected:
};
#endif