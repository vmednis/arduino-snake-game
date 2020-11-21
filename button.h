#pragma once
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

class Button {
  public:
    Button(uint8_t pin, void (*isr)());
    void handleInterrupt();
    bool isPressed();
  private:  
    bool pressed = false;
};
