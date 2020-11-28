#include "button.h"
#include "game/snake.h"
#include "game/fruit.h"
#include "renderer.h"

CREATE_INTERRUPT_BUTTON(buttonUp, 23);
CREATE_INTERRUPT_BUTTON(buttonDown, 19);
CREATE_INTERRUPT_BUTTON(buttonLeft, 18);
CREATE_INTERRUPT_BUTTON(buttonRight, 17);

Snake snake;
Fruit fruit(&snake);

void setup() {
  Serial.begin(115200);
  Renderer::initialize();
}

void loop() {
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
