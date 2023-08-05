#ifndef EXTBOARDGPIO_h
#define EXTBOARDGPIO_h

#include <Arduino.h>
// Opto input pin
#define D1_PIN (1) // IN1 !!! WARNING: D2 on schematic = D1 on board label (3.3-12v)
#define D2_PIN (0) // IN2 !!! WARNING: D1 on schematic = D2 on board label (3.3-12v)
// Relay output pin
#define Relay1 (4)
#define Relay2 (5)
#define Relay3 (6)
#define Relay4 (7)
// IO/Analog
#define A1_PIN 32 // ADC 0-3.3V, 5V(Max) ESP32 pin 32
#define A2_PIN 33 // ADC 0-3.3V, 5V(Max) ESP32 pin 33
#define D3_PIN 27 // Digital ESP pin 27
//LCD PIN
#define LCD_RST (3)
#define LCD_BL (2)


#endif