#pragma once


#include "game/snake.h"
#include "game/position.h"
#include "game/fruit.h"

namespace Renderer {
  void initialize();
  void renderBorder();
  void renderSnake(Snake *snake);
  void renderFruit(Fruit *fruit);
  void renderGameOver(Snake *snake);
  void startFrame();
  void endFrame();
}
