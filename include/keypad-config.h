#include <Arduino.h>
#include <pin-config.h>
#pragma once

extern char userArrayKey [];
extern char secretPassword [];
extern char keypad [ROW_NUM][C_NUM];
char scan(char [][C_NUM]);
bool validateKey(const char[], char []);
bool saveUserKey(char [], char);
bool isKeypadPressed();

