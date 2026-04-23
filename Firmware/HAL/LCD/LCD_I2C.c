
#define F_CPU 16000000UL
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <avr/io.h>
#include "../MCAL/TWI.h"
#include "../HAL/LCD_I2C/LCD_I2C.h"
#include "../HAL/LCD_I2C/LCD_I2C_CONF.h"
#include "../MCAL/UART.h"


#define LCD_ADDR 0x27 
#define RS 0x01  
#define RW 0x02  
#define EN 0x04  
#define BL 0x08  

// LCD commands
#define LCD_CLEAR 0x01
#define LCD_HOME 0x02
#define LCD_ENTRY_MODE 0x06
#define LCD_DISPLAY_ON 0x0C
#define LCD_DISPLAY_OFF 0x08
#define LCD_CURSOR_ON 0x0E
#define LCD_CURSOR_BLINK 0x0F
#define LCD_4BIT_MODE 0x28
#define LCD_SET_CURSOR 0x80

static uint8_t backlight_state = BL;

// Send nibble to LCD
void LCD_sendNibble(uint8_t nibble) {
	uint8_t data = (nibble & 0xF0) | backlight_state;
	
	I2C_start();
	I2C_write(LCD_ADDR << 1); 
	
	// Send data with EN high
	I2C_write(data | EN);
	_delay_us(1);
	
	// Send data with EN low (latch)
	I2C_write(data);
	_delay_us(50);
	
	I2C_stop();
}

// Send byte to LCD
void LCD_sendByte(uint8_t data, uint8_t mode) {
	uint8_t high_nibble = data & 0xF0;
	uint8_t low_nibble = (data << 4) & 0xF0;
	
	I2C_start();
	I2C_write(LCD_ADDR << 1);
	
	// Send high nibble with EN pulse
	I2C_write(high_nibble | mode | backlight_state | EN);
	_delay_us(1);
	I2C_write(high_nibble | mode | backlight_state);
	_delay_us(50);
	
	// Send low nibble with EN pulse
	I2C_write(low_nibble | mode | backlight_state | EN);
	_delay_us(1);
	I2C_write(low_nibble | mode | backlight_state);
	_delay_us(50);
	
	I2C_stop();
}

// Send command to LCD
void LCD_command(uint8_t cmd) {
	LCD_sendByte(cmd, 0);
	if (cmd == LCD_CLEAR || cmd == LCD_HOME)
	_delay_ms(2);
}

// Send data (character) to LCD
void LCD_data(uint8_t data) {
	LCD_sendByte(data, RS);
}

// Initialize LCD
void LCD_init(void) {
	I2C_init();
	_delay_ms(50); 
	
	// Initialize in 4-bit mode
	LCD_sendNibble(0x30);
	_delay_ms(5);
	LCD_sendNibble(0x30);
	_delay_us(150);
	LCD_sendNibble(0x30);
	_delay_us(150);
	LCD_sendNibble(0x20); // Set to 4-bit mode
	_delay_us(150);
	
	// Configure LCD
	LCD_command(LCD_4BIT_MODE);    // 4-bit, 2 lines, 5x8 font
	LCD_command(LCD_DISPLAY_OFF);   // Display off
	LCD_command(LCD_CLEAR);         // Clear display
	LCD_command(LCD_ENTRY_MODE);    // Entry mode: increment, no shift
	LCD_command(LCD_DISPLAY_ON);    // Display on, cursor off
}

// Clear LCD
void LCD_clear(void) {
	LCD_command(LCD_CLEAR);
}

// Set cursor position 
void LCD_setCursor(uint8_t row, uint8_t col) {
	uint8_t row_offsets[] = {0x00, 0x40, 0x14, 0x54};
	LCD_command(LCD_SET_CURSOR | (col + row_offsets[row]));
}

// Print string
void LCD_print(const char* str) {
	while (*str) {
		LCD_data(*str++);
	}
}

// Print string from program memory
void LCD_printPgm(const char* str) {
	char c;
	while ((c = pgm_read_byte(str++))) {
		LCD_data(c);
	}
}

// Control backlight
void LCD_backlight(uint8_t state) {
	backlight_state = state ? BL : 0;
	I2C_start();
	I2C_write(LCD_ADDR << 1);
	I2C_write(backlight_state);
	I2C_stop();
}
