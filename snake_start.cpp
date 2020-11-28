#include "snake_start.h"

Button ButtonUp;
Button ButtonDown;
Button ButtonLeft;
Button ButtonRight;

Snake snake;
Fruit fruit(&snake);

void snake() {
	//Renderer::initialize();
	while(1){
		if (buttonUp.isPressed()) snake.turn(UP);
		if (buttonDown.isPressed()) snake.turn(DOWN);
		if (buttonLeft.isPressed()) snake.turn(LEFT);
		if (buttonRight.isPressed()) snake.turn(RIGHT);

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
