/*
 * snake_start.h
 *
 *  Created on: Nov 28, 2020
 *      Author: Norbert
 */

//#ifndef SRC_SNAKE_GAME_SNAKE_START_H_
//#define SRC_SNAKE_GAME_SNAKE_START_H_
#pragma once

#include "snake_start.h"

#ifdef __cplusplus
 extern "C" {
#endif

void delay(int delay);
extern void snake_start(void*);
void snake_button(short control);
long millis();



#ifdef __cplusplus
}
#endif
//#endif /* SRC_SNAKE_GAME_SNAKE_START_H_ */
