#include "snake_start.h"
#include "game/button.h"
#include "game/fruit.h"
#include "renderer.h"
#ifndef ARDUINO
#include "stm32f3xx_hal.h"
#include <stdlib.h>
#endif

#ifdef ARDUINO
CREATE_INTERRUPT_BUTTON(buttonEnd, 1);
CREATE_INTERRUPT_BUTTON(buttonUp, 23);
CREATE_INTERRUPT_BUTTON(buttonDown, 19);
CREATE_INTERRUPT_BUTTON(buttonLeft, 18);
CREATE_INTERRUPT_BUTTON(buttonRight, 17);
#else
Button buttonUp;
Button buttonDown;
Button buttonLeft;
Button buttonRight;
Button buttonEnd;
#endif
Snake snake;
Fruit fruit(&snake);


void snake_start(void* u8g2) {
#ifdef ARDUINO
	Renderer::initialize();
#else
	Renderer::initialize(u8g2);
	while(1){
		if (buttonEnd.isPressed()) 		break;
		if (buttonUp.isPressed()) 		snake.turn(UP);
		if (buttonDown.isPressed()) 	snake.turn(DOWN);
		if (buttonLeft.isPressed()) 	snake.turn(LEFT);
		if (buttonRight.isPressed()) 	snake.turn(RIGHT);

		bool resetFruit = false;
		if(snake.nextHeadPosition() == fruit.getPosition()) {
			snake.grow();
			resetFruit = true;
		}

		snake.advance();
		if(resetFruit) fruit.randomize(&snake);
		  
		Renderer::startFrame();
		Renderer::renderBorder();
		Renderer::renderSnake(&snake);
		Renderer::renderFruit(&fruit);
		if(!snake.isAlive()) Renderer::renderGameOver(&snake);
		Renderer::endFrame();
		
		delay(150);
	}
#endif
}

//This function is called by STM32 button interrupt with proper parameter corresponding the right button
//You can use this approach or make yours
#ifndef ARDUINO
void snake_button(short control){
	if(control == END) 		buttonEnd.pressed = true;
	if(control == UP)		buttonUp.pressed = true;
	if(control == DOWN) 	buttonDown.pressed = true;
	if(control == RIGHT)	buttonRight.pressed = true;
	if(control == LEFT)		buttonLeft.pressed = true;
}
#endif
//Fill these functions
void delay(int delay){
#ifdef ARDUINO
	delay(delay);
#else
	HAL_Delay(delay);
#endif
}

//Fill these functions
long micros(){
#ifdef ARDUINO
	return micros();
#else
	return HAL_GetTick()*1000;
#endif
}

//Fill these functions
int get_random_value(int spaceCnt){
#ifdef ARDUINO
	return random(0, spaceCnt);
#else
	srand (HAL_GetTick()); //not the best
	return rand() % spaceCnt;
	return 0;
#endif
}
