
#include <Arduino.h>
#include "IO_EXPANDER.h"

IO_EXPANDER::IO_EXPANDER(uint8_t address, TwoWire *bus)
{
    _ext = new PCA9557(address, bus);
}
// PCA9557 _ext(0x19, &Wire);

IO_EXPANDER::IO_EXPANDER()
{
    _ext = new PCA9557(0x19, &Wire);
}

void IO_EXPANDER::begin()
{
    Serial.println(F("[IO Expander] begin"));
    Wire.begin();
    _ext->pinMode(Relay1, OUTPUT);
    _ext->pinMode(Relay2, OUTPUT);
    _ext->pinMode(Relay3, OUTPUT);
    _ext->pinMode(Relay4, OUTPUT);
    _ext->digitalWrite(Relay1, OUTPUT);
    _ext->digitalWrite(Relay2, OUTPUT);
    _ext->digitalWrite(Relay3, OUTPUT);
    _ext->digitalWrite(Relay4, OUTPUT);
    _ext->pinMode(LCD_BL, OUTPUT);
    _ext->pinMode(LCD_RST, OUTPUT);
}

bool IO_EXPANDER::read(RELAY RelayChannel)
{
    bool status = false;
    switch (RelayChannel)
    {
    case RELAY::CH1:
        status = !_ext->digitalRead(Relay1);
        break;
    case RELAY::CH2:
        status = !_ext->digitalRead(Relay2);
        break;
    case RELAY::CH3:
        status = !_ext->digitalRead(Relay3);
        break;
    case RELAY::CH4:
        status = !_ext->digitalRead(Relay4);
        break;
    default:
        break;
    }
    return status;
}

void IO_EXPANDER::set(RELAY RelayChannel, int value)
{
    switch (RelayChannel)
    {
    case RELAY::CH1:
        _ext->digitalWrite(Relay1, value);
        break;
    case RELAY::CH2:
        _ext->digitalWrite(Relay2, value);
        break;
    case RELAY::CH3:
        _ext->digitalWrite(Relay3, value);
        break;
    case RELAY::CH4:
        _ext->digitalWrite(Relay4, value);
        break;
    default:
        break;
    }
}

bool IO_EXPANDER::read(DIN digitalINPUT)
{
    bool status = false;
    switch (digitalINPUT)
    {
    case DIN::D1:
        status = !_ext->digitalRead(D1_PIN);
        break;
    case DIN::D2:
        status = !_ext->digitalRead(D2_PIN);
        break;
    default:
        break;
    }
    return status;
}

// GPIO ON Board

uint16_t IO_EXPANDER::read(AIN analogINPUT)
{
    uint16_t analog_value = 0;
    switch (analogINPUT)
    {
    case AIN::A1:
        analog_value = analogRead(A1_PIN);
        break;
    case AIN::A2:
        analog_value = analogRead(A2_PIN);
        break;
    default:
        break;
    }
    return analog_value;
}

void IO_EXPANDER::set(AIN analogIO, int value)
{
    switch (analogIO)
    {
    case AIN::A1:
        digitalWrite(A1_PIN, value);
        break;
    case AIN::A2:
        digitalWrite(A2_PIN, value);
        break;
    default:
        break;
    }
}

bool readOnBoard(int _pin)
{
    return digitalRead(_pin);
}
void writeOnBoard(int _pin, int value)
{
    digitalWrite(_pin, value);
}
void setOnBoard(int _pin, int mode)
{
    pinMode(_pin, mode);
}

bool IO_EXPANDER::read(DIGITAL digitalIO)
{
    bool status = false;
    if (digitalIO == DIGITAL::D3)
    {
        status = readOnBoard(D3_PIN);
    }
    return status;
}

void IO_EXPANDER::set(DIGITAL digitalIO, int value)
{
    if (digitalIO == DIGITAL::D3)
    {
        writeOnBoard(D3_PIN, value);
    }
}

void IO_EXPANDER::setMode(DIGITAL digitalIO, int mode)
{
    if (digitalIO == DIGITAL::D3)
    {
        setOnBoard(D3_PIN, mode);
    }
    else
    {
        return;
    }
}

// 1.0.1

/// @details get raw pin Analog
int IO_EXPANDER::getPinAIN(AIN analogINPUT)
{
    if (analogINPUT == AIN::A1)
    {
        return A1_PIN;
    }
    else if (analogINPUT == AIN::A2)
    {
        return A2_PIN;
    }
    return -1;
}

/// @details get raw pin Digital
int IO_EXPANDER::getPinDIO(DIGITAL digitalIO)
{
    if (digitalIO == DIGITAL::D3)
    {
        return D3_PIN;
    }
    return -1;
}
int IO_EXPANDER::getPinDIN(DIN digitalINPUT)
{
    if (digitalINPUT == DIN::D1)
    {
        return D1_PIN;
    }
    else if (digitalINPUT == DIN::D2)
    {
        return D2_PIN;
    }
    return -1;
}

void IO_EXPANDER::set(LCD lcdIO, int value)
{
    switch (lcdIO)
    {
    case LCD::BL:
        _ext->digitalWrite(LCD_BL, value);
        break;
    case LCD::RST:
        _ext->digitalWrite(LCD_RST, value);
        break;
    default:
        break;
    }
}

bool IO_EXPANDER::read(LCD lcdIO)
{
    bool status = false;
    switch (lcdIO)
    {
    case LCD::BL:
        status = !_ext->digitalRead(LCD_BL);
        break;
    case LCD::RST:
        status = !_ext->digitalRead(LCD_RST);
        break;
    default:
        break;
    }
    return status;
}

int IO_EXPANDER::getPinLCD(LCD lcd)
{
    if (lcd == LCD::BL)
    {
        return LCD_BL;
    }
    else if (lcd == LCD::RST)
    {
        return LCD_RST;
    }
    return -1;
}
