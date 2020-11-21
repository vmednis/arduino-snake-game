#include "Arduino.h"
#include "button.h"

Button::Button(uint8_t pin, void (*isr)()) {
  pinMode(pin, INPUT_PULLUP);
  attachInterrupt(pin, isr, FALLING);
}

void Button::handleInterrupt() {
  pressed = true;
}

bool Button::isPressed() {
  bool res = this->pressed;
  this->pressed = false;
  return res;
}
