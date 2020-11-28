/*
 * u8g2_callback.c
 *
 *  Created on: 2020. nov. 22.
 *      Author: Norbert
 */
#ifndef ARDUINO
#include "u8g2_callback.h"

u8g2_t u8g2;


uint8_t u8x8_stm32_gpio_and_delay(U8X8_UNUSED u8x8_t *u8x8,
    U8X8_UNUSED uint8_t msg, U8X8_UNUSED uint8_t arg_int,
    U8X8_UNUSED void *arg_ptr)
{
  switch (msg)
  {
  case U8X8_MSG_GPIO_AND_DELAY_INIT:
    HAL_Delay(1);
    break;
  case U8X8_MSG_DELAY_MILLI:
    HAL_Delay(arg_int);
    break;
  case U8X8_MSG_GPIO_I2C_CLOCK:		// arg_int=0: Output low at I2C clock pin

	  break;							// arg_int=1: Input dir with pullup high for I2C clock pin
  case U8X8_MSG_GPIO_I2C_DATA:			// arg_int=0: Output low at I2C data pin

	  break;
  }
  return 1;
}

uint8_t u8x8_byte_stm32_hw_i2c(u8x8_t *u8g2, uint8_t msg, uint8_t arg_int, void *arg_ptr) {
	static uint8_t dc = 0;
	switch(msg)  {
		case U8X8_MSG_BYTE_SEND:
			while (HAL_I2C_STATE_READY != HAL_I2C_GetState(&hi2c1)) { }
			HAL_I2C_Mem_Write(&hi2c1, SSD1306_I2C_ADDR, (dc == 0)?0:0x40, 1, (uint8_t *)arg_ptr, arg_int, HAL_MAX_DELAY);
			break;
		case U8X8_MSG_BYTE_INIT:
			u8g2->gpio_and_delay_cb(u8g2, U8X8_MSG_DELAY_NANO, u8g2->display_info->post_chip_enable_wait_ns, NULL);
			break;
		case U8X8_MSG_BYTE_SET_DC:
			dc = arg_int;
			break;
		case U8X8_MSG_BYTE_START_TRANSFER:
			break;
		case U8X8_MSG_BYTE_END_TRANSFER:
			break;
		default:
			return 0;
	}
	return 1;}
#endif
