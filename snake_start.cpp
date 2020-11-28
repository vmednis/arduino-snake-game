#include "stm32f3xx_hal.h"

#include "snake_start.h"
#include "button.h"
#include "snake_start.h"
#include "game/fruit.h"
#include "renderer.h"


Button buttonUp;
Button buttonDown;
Button buttonLeft;
Button buttonRight;
Button buttonEnd;

Snake snake;
Fruit fruit(&snake);

/*void rend(void* u8g2){
	//Renderer::initialize(u8g2);
}
*/
void snake_start(void* u8g2) {
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
  
}

void snake_button(short control){
	if(control == END) 		buttonEnd.pressed = true;
	if(control == UP)		buttonUp.pressed = true;
	if(control == DOWN) 	buttonDown.pressed = true;
	if(control == RIGHT)	buttonRight.pressed = true;
	if(control == LEFT)		buttonLeft.pressed = true;
}

void delay(int delay){
	HAL_Delay(delay);
}

long millis(){
	return HAL_GetTick();
}
