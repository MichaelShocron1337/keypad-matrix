#include <Arduino.h>
#pragma once
// Arduino Uno pins, inte esp32
// ROW är output = LOW
#define ROW1 2
#define ROW2 3
#define ROW3 4
#define ROW4 5
#define RGB_PIN_RED 6 // 6
#define RGB_PIN_GREEN 7 // 7
//Column är HIGH = PULLUP input
#define C1 8 // 8
#define C2 9
#define C3 10
#define C4 11 // 11
//Knapp
#define START_BUTTON 12 // 12


#define ROW_NUM 4
#define C_NUM 4
extern const int ColPin [];
extern const int rowPin[];

void pin_activation();
bool isStartButtonPressed();
