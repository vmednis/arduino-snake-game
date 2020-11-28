#include "renderer.h"
#include "U8g2lib.h"

#define CELL_SIZE 8

namespace Renderer {

	//u8g2_Setup_ssd1306_128x64_noname_f(&u8g2, U8G2_R0, u8x8_byte_stm32_hw_i2c, u8x8_stm32_gpio_and_delay);

  void initialize() {
	u8g2_InitDisplay(&u8g2);
    u8g2_SetFont(&u8g2,u8g2_font_6x10_tf);
  }

  unsigned long time_total = 0;
  unsigned long time_last = 0;
  float framerate() {
    time_last = time_total;
    time_total = micros();
    return 1.0 / ((time_total - time_last) / 1000000.0);
  }

  void renderBorder() {
    u8g2_DrawFrame(&u8g2,0, 0, 128, 64);
  }
  
  void renderSnake(Snake *snake) {
    const uint8_t **body = snake->getBody();
    for(int i = 0; i < Snake::BODY_WIDTH; i++) {
      for(int j = 0; j < Snake::BODY_HEIGHT; j++) {
        if(body[i][j] > 0) {
          u8g2_DrawBox(&u8g2, i * CELL_SIZE, j * CELL_SIZE, CELL_SIZE, CELL_SIZE);
        }
      }
    }
  }

  void renderFruit(Fruit * fruit) {
    Position position = fruit->getPosition();
    u8g2_DrawFrame(&u8g2, position.x * CELL_SIZE + 1, position.y * CELL_SIZE + 1, CELL_SIZE - 2, CELL_SIZE - 2);
  }

  void renderGameOver(Snake *snake) {
    u8g2_DrawBox(&u8g2, 32, 20, 64, 22);
    u8g2_SetDrawColor(&u8g2,0);
    u8g2_DrawStr(&u8g2, 34, 30, "Game Over!");
    u8g2_DrawStr(&u8g2, 34, 40, "Points: ");
    u8g2_DrawStr(&u8g2, 34, 52, snake->getPoints());
    u8g2_SetDrawColor(&u8g2, 1);
  }

  void startFrame() {
    u8g2_ClearBuffer(&u8g2);
  }

  void endFrame() {
    u8g2_SendBuffer(&u8g2);
  }

}
