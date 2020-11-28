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

void snake_button_is_pressed(int16_t GPIO_Pin){
	static uint32_t last_time;
	switch (GPIO_Pin){
	case ENCODER_PUSH_BUTTON_Pin:
		if(is_long_pressed){
			return;
		}
		break;

	}
}

void set_control(short control){
	direction = control;
}
