#include "button.h"

void Button::handleInterrupt() {
  pressed = true;
}

bool Button::isPressed() {
  bool res = this->pressed;
  this->pressed = false;
  return res;
}


Button::Button(){
	this->pressed = false;
}

