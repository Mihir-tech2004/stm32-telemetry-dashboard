#ifndef INC_SSD1306_H_
#define INC_SSD1306_H_

#include "main.h"

#define SSD1306_I2C_ADDR        0x78
#define SSD1306_WIDTH           128
#define SSD1306_HEIGHT          64

void SSD1306_Init(I2C_HandleTypeDef *hi2c);
void SSD1306_Clear(void);
void SSD1306_UpdateScreen(void);
void SSD1306_GotoXY(uint8_t x, uint8_t y);
void SSD1306_Puts(char* str);

#endif /* INC_SSD1306_H_ */
