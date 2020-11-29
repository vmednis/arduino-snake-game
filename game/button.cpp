#include "button.h"

void Button::handleInterrupt() {
  pressed = true;
}

bool Button::isPressed() {
  bool res = this->pressed;
  this->pressed = false;
  return res;
}

#ifdef ARDUINO
Button::Button(uint8_t pin, void (*isr)()) {
  pinMode(pin, INPUT_PULLUP);
  attachInterrupt(pin, isr, FALLING);
}
#else
Button::Button(){
	this->pressed = false;
}
#endif
