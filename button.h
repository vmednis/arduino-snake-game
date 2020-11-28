#pragma once


#define LONG_PRESS	3000
#define	UP			1
#define	DOWN		2
#define	LEFT		3
#define	RIGHT		4

class Button {
  public:
    Button(uint8_t pin, void (*isr)());
    void handleInterrupt();
    bool isPressed();
  private:  
    bool pressed = false;
};
