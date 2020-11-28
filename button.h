#pragma once

#define LONG_PRESS	3000

typedef unsigned char uint8_t;

class Button {
  public:
    Button();
    void handleInterrupt();
    bool isPressed();
    bool pressed = false;
};
