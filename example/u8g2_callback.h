/*
 * u8g2_callback.h
 *
 *  Created on: 2020. nov. 22.
 *      Author: Norbert
 */
#ifndef ARDUINO
#ifndef INC_U8G2_CALLBACK_H_
#define INC_U8G2_CALLBACK_H_

#define SSD1306_I2C_ADDR        0x78

#include "main.h"
#include "u8g2.h"

extern  u8g2_t u8g2;


uint8_t u8x8_stm32_gpio_and_delay(U8X8_UNUSED u8x8_t *u8x8,
    U8X8_UNUSED uint8_t msg, U8X8_UNUSED uint8_t arg_int,
    U8X8_UNUSED void *arg_ptr);
uint8_t u8x8_byte_stm32_hw_i2c(u8x8_t *u8g2, uint8_t msg, uint8_t arg_int, void *arg_ptr);

#endif /* INC_U8G2_CALLBACK_H_ */
#endif //Arudino
