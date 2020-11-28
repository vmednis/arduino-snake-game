#include "button.h"

void Button::handleInterrupt() {
  pressed = true;
}

bool Button::isPressed() {
  bool res = this->pressed;
  this->pressed = false;
  return res;
}



void set_control(short control){
	if(control == LEFT) 	buttonLeft.pressed = true;
	if(control == RIGHT)	buttonRight.pressed = true;
	if(control == UP) 	buttonLeft.pressed = true;
	if(control == DOWN)	buttonRight.pressed = true;
}
