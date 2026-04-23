
#ifndef LCD_I2C_H_
#define LCD_I2C_H_
#include <stdint.h>

void LCD_init(void);
void LCD_clear(void);
void LCD_setCursor(uint8_t row, uint8_t col);
void LCD_print(const char* str);
void LCD_printPgm(const char* str);
void LCD_backlight(uint8_t state);
void LCD_command(uint8_t cmd);
void LCD_data(uint8_t data);
void LCD_sendByte(uint8_t data, uint8_t mode);
void LCD_sendNibble(uint8_t nibble);


#endif /* LCD_I2C_H_ */
