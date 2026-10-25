#include <Arduino.h>
#include <stdio.h>
#include <pin-config.h>
#include <keypad-config.h>

char userArrayKey [4] = {'0', '0', '0', '0'};
char secretPassword [] = {'1', '3', '3', '7'};

char keypad[ROW_NUM][C_NUM] = 
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

char scan (char keypadArray [][C_NUM])
{
  
  char keyPressedByUser = '\0';
  for(int rad = 0; rad < ROW_NUM;rad++)
  {
    pinMode(rowPin[rad], OUTPUT);
    digitalWrite(rowPin[rad], LOW);
    for(int kolumn = 0; kolumn < C_NUM; kolumn++)
    {
      if(!digitalRead(ColPin[kolumn]))// false = LOW
      {
        keyPressedByUser = keypad[rad][kolumn];
      } 
    }
    pinMode(rowPin[rad], INPUT);
  }
  return keyPressedByUser;
}

bool validateKey(const char secretPassword[], char userArray [])
{
  int length = 4;

  for(int i = 0; i <= length; i++)
  {
    if(secretPassword[i] != userArray[i])
    {
      return false;
    }
  }
  return true;

}


bool saveUserKey(char userArrayKey []  ,char LatestKeyPressed)
{
  // anvädner userarray, position = sätter in värdet från parametern
  // behöver dock lägga till att om den är null så bör den retunera false
  // lägger den nu sist i arrayn
  if(LatestKeyPressed == '\0')
  {
    return false;
  }

  for(int i = 0; i < 3; i++)
  {
    userArrayKey[i] = userArrayKey[i+1];
  }

  userArrayKey[3] = LatestKeyPressed;
  return true;
  
}

bool isKeypadPressed()
{ // alla input är high
  bool flagga = false;
  for(int rad = 0; rad < ROW_NUM ;rad++)
  {
    pinMode(rowPin[rad], OUTPUT);
    digitalWrite(rowPin[rad], LOW);
    /* 
    Måste omvandla denna från high-Z till low så att när knappen trycks går den till gnd = low = 0
    */
    for(int kolumn = 0; kolumn < C_NUM; kolumn++)
    {
      if(!digitalRead(ColPin[kolumn]))// false = OM den retunerar 0 utför instruktion
      {
        flagga = true;
        break;
      } 
    }
    pinMode(rowPin[rad], INPUT);
    if(flagga)
    {
      return true;
    }
  }

  return false;
}