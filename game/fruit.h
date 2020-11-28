#pragma once

#include "snake.h"
#include "position.h"
//#define uint8_t int
class Fruit {
  public:
    Fruit(Snake * snake);
    void randomize(Snake * snake);
    const Position getPosition();
  private:
    Position position { Position(0, 0) };
};
