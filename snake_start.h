/*
 * snake_start.h
 *
 *  Created on: Nov 28, 2020
 *      Author: Norbert
 */

#pragma once

//#define ARDUINO


#ifdef __cplusplus
 extern "C" {
#endif

void snake_start(void*);
void snake_button(short control);

#ifdef __cplusplus
}

void delay(int delay);
long millis();
int get_random_value(int spaceCnt);

#endif
//#endif /* SRC_SNAKE_GAME_SNAKE_START_H_ */
