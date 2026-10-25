#include <Arduino.h>
#include <stdio.h>
#include <pin-config.h>
#include <LED-config.h>

// Allt som berör LED
bool isLedActice = false;
unsigned long  startingTime = 0;
void keypadPressBlink()
{
  digitalWrite(RGB_PIN_RED,LOW);
  startingTime = millis();
  digitalWrite(RGB_PIN_RED, HIGH);
  isLedActice = true;
}

void updateLED()
{
  
  if(millis() - startingTime >= 350 && isLedActice)
  {
    digitalWrite(RGB_PIN_RED, LOW);
    isLedActice = false;
  }
}

void greenLight() 
{
  digitalWrite(RGB_PIN_RED, LOW);
  digitalWrite(RGB_PIN_GREEN, HIGH);
  isLedActice = true;
  delay(3000);
}

void returnToIdle()
{
  digitalWrite(RGB_PIN_GREEN, LOW);
}

void RGB_green()
{
  digitalWrite(RGB_PIN_RED, LOW);
  digitalWrite(RGB_PIN_GREEN, HIGH);
}
