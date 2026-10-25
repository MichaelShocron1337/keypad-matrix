#include <Arduino.h>
#include <stdio.h>
#include <pin-config.h>

const int ColPin [] = {C1, C2, C3, C4}; // dessa är bara defines som har egen index
const int rowPin [] = {ROW1, ROW2, ROW3, ROW4}; // även i om row1 är endast 1 index, så
// motsvarar den en hel rad på själva matrissen, det är drf


bool isStartButtonPressed()
{
  if(digitalRead(START_BUTTON) == LOW)
  {
    return true;
  }

  return false;
}

void pin_activation()
{
  for(int pin_highZ = 2; pin_highZ <=5; pin_highZ++)
  {
    pinMode(pin_highZ, INPUT);
    // highz, varken high eller Low

  }

  for(int pin_input_pullUp = 8; pin_input_pullUp <= 12; pin_input_pullUp++)
  {
    pinMode(pin_input_pullUp, INPUT_PULLUP);
  }

  pinMode(RGB_PIN_RED, OUTPUT);
  pinMode(RGB_PIN_GREEN, OUTPUT);
  digitalWrite(RGB_PIN_RED, LOW);
  digitalWrite(RGB_PIN_GREEN, LOW);
}