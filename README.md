# Snake Game

**Snake game running various mikroprocessor, displayed with u8g2 driver on any small display, developed in C++.**

This repository is forked from [arduino-snake-game](https://github.com/vmednis/arduino-snake-game). For more info check it.\
Main modifications were porting to STM32 microcontroller, simpler files structure and much better portability for any low cost microprocessor system.

Input pins can be changed in the main sketch file. It should be easily portable to other displays, just change the `renderer.cpp` and if needed adjust board size in `snake.h` too.

## Portability ##

As it is, its runnable on STM32F3 microprocessor family you only need to provide some startup code and settings for desired microprocessor (with CubeMX, stm32ide, etc.).

With main macro switch in ``` snake_start.h ``` file you can switch between Arduino and microprocessors.

For other microprocessors you must provide own codes for: 
 - writing on display with u8g2 (see the examples section)
 - buttons handling
 - miliseconds delay 
 - get elapsed microseconds
 - random number generator
 
 Launching the game is initiated with calling ```snake_start(void* u8g2)``` function.
