#pragma once

#include "snake.h"
#include "position.h"
#include "snake_start.h"
#ifdef ARDUINO
#include "Arduino.h"
#endif

class Fruit {
  public:
    Fruit(Snake * snake);
    void randomize(Snake * snake);
    const Position getPosition();
  private:
    Position position { Position(0, 0) };
};
