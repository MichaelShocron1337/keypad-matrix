#include <Arduino.h>
#include <stdio.h>
#include <pin-config.h>
#include <LED-config.h>
#include <keypad-config.h>

// behöver knappen som startar
void setup()
{
  init();
  pin_activation();
  Serial.begin(9600);
}

int main(void)
{
  enum state 
  {
    IDLE,
    SUCCESSFUL_PIN_CODE,
    SCANNING,
    VALIDATING,
    WAIT_TO_START

  };
  state currentState = WAIT_TO_START;

setup();
bool keyWasPressed = false;

  while(1)
  {
    updateLED();
    switch(currentState)
    {
      case WAIT_TO_START:
      {
        
        if(isStartButtonPressed())
        {
          Serial.println("Pressed");
          keypadPressBlink();
          updateLED();
          currentState = IDLE;
        }
        break;
      }

      

      case IDLE:
      {
        bool isKeyPressedNow = isKeypadPressed();
        if(isKeyPressedNow && !keyWasPressed)
        {
          keypadPressBlink();
          Serial.println("Pressed");
          currentState = SCANNING;
        }
        keyWasPressed = isKeyPressedNow;
        break;
      }
      case SCANNING:
      {
        char LatestKeyStroke = '\0';
        LatestKeyStroke = scan(keypad); // sparar Char från scan
        if(saveUserKey(userArrayKey, LatestKeyStroke))
        // increment bara om det inte är null
        {
          currentState = VALIDATING;
        }
        else
        {
          currentState = IDLE;
        }
        break;
      }
      case VALIDATING:
      {
        if(validateKey(secretPassword, userArrayKey))
        {
          currentState = SUCCESSFUL_PIN_CODE;
          break;
        }
        else
        {
          currentState = IDLE;
          break;
        }
        
      }
      case SUCCESSFUL_PIN_CODE:
      {
        greenLight();
        returnToIdle();
        currentState = IDLE;
        break;
      }
    }
  }
}
