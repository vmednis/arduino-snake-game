#pragma once

#include "snake_start.h"
#include "game/snake.h"
#include "game/position.h"
#include "game/fruit.h"
#include "U8g2.h"



namespace Renderer {
  void initialize(void*);
  void renderBorder();
  void renderSnake(Snake *snake);
  void renderFruit(Fruit *fruit);
  void renderGameOver(Snake *snake);
  void startFrame();
  void endFrame();
}

int intToStr(int x, char str[], int d);
