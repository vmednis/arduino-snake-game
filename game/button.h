#pragma once

#define LONG_PRESS	3000

#ifndef ARDUINO
typedef unsigned char uint8_t;
#else
#include "Arduino.h"

//unfortunately for interrupts to work buttons have to be defined globally.
#define CREATE_INTERRUPT_BUTTON(NAME, PIN) \
void _## NAME ##HandleISR(); \
void IRAM_ATTR _## NAME ##ISR() { \
  _## NAME ##HandleISR(); \
}; \
Button NAME(PIN, _## NAME ##ISR); \
void _## NAME ##HandleISR() { \
  NAME.handleInterrupt(); \
};
#endif

class Button {
  public:
    Button();
    void handleInterrupt();
    bool isPressed();
    bool pressed = false;
};
