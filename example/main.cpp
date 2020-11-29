/*
 * main.cpp
 *
 *  Created on: Nov 29, 2020
 *      Author: Norbert
 */
#include "snake_start.h"
#include "u8g2_callback.h"


int main(){
	  u8g2_Setup_ssd1306_128x64_noname_f(&u8g2, U8G2_R0, u8x8_byte_stm32_hw_i2c, u8x8_stm32_gpio_and_delay);
	  u8g2_InitDisplay(&u8g2);
	  u8g2_SetPowerSave(&u8g2, 0);
}


