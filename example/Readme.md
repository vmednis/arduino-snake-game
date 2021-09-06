### STM32 and others ###
```main.cpp, u8g2_callback.c, u8g2_callback.h``` is example files for STM32 or any other microcontroller.
In ```u8g2_callback.c, u8g2_callback.h``` you need to provide prototype functions for write display through u8g2 driver. Form STM32 family microprocessor only very minor modifications is needed. This is only an example, it does not work on its own.

### Arduino ###
```snake-game.ino``` is example for Arduino. Its much simpler beacuse you do not need to provide own functions for writing on display throug u8g2 driver.
