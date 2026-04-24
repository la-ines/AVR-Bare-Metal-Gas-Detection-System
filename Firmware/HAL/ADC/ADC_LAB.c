
#include "../MCAL/DIO_types.h"
#include "../MCAL/DIO1.h"
#include "../MCAL/Bit_Math.h"
#include "../MCAL/ADC/ADC.h"
#include "../HAL/LCD/LCD.h"
#include "../APP/ADC_LAB.h"
#include "../MCAL/UART.h"
#include "../MCAL/UART_reg.h"
#include  "../APP/LCD_app.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/LCD_I2C/LCD_I2C.h"

#define F_CPU 16000000UL
#include <util/delay.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>


void ADC_Lab(void) {
	uint16_t value;
	uint16_t last_value = 0;
	// LCD and ADC Initialization
	Lcd_initialize(); 
	_delay_ms(100);
	ADC_Initialize();
	
	

	while (1) {
		ADC_StartConversion(ADC_Channel_1);
		value = ADC_GetResult();
		
				
				if (value != last_value) {
					char buffer[20];
					snprintf(buffer, sizeof(buffer),"ADC: %4d", value); 
				// Line 1, Column 5 (after "ADC: ") // Format as 4 digits
					
					
					last_value = value;  // Save the new value
				}
				_delay_ms(200);  // Short delay to reduce flicker
	} 
	}
	
