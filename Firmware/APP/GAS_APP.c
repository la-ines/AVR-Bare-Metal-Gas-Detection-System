
#include "../MCAL/DIO_types.h"
#include "../HAL/LCD_I2C/LCD_I2C.h"
#include "../MCAL/DIO1.h"
#include "../MCAL/Bit_Math.h"
#include "../MCAL/ADC/ADC.h"
#include "../APP/gas sensor/GAS_APP.h"
#include "../MCAL/UART.h"
#include "../MCAL/UART_reg.h"
#include "delay_function.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>
uint16_t adc_value;

void GAS_APP() {
	
	 DIO_SetPinDirection(DIO_PORTD, Pin7, Output);
	ADC_Initialize();
	LCD_init();       
	UART_initialize();

	while (1) {
		// Start ADC conversion 
		ADC_StartConversion(ADC_Channel_1);
		adc_value = ADC_GetResult();          
		// Calculate VOUT and RS
		float VOUT = (float)adc_value * V_REF / 1023.0; //output voltage 
		float RS = R_L * ((5.0 - VOUT) / VOUT);   // resistance of sensor
		float PPM = A * pow((RS / R0), B);   //unit of concentration often used to measure the amount of gas (toxic gas such as CO2 ,NH3...) in the air
       //buzzer on when air is toxic
        if(adc_value > 70)
		{UART_Send_String("buzzer on");
			UART_Send_String("\r\n");
	        DIO_SetPinValue(DIO_PORTD, Pin7, HIGH);
       
		Delay_ms(100);}
		else{
			DIO_SetPinValue(DIO_PORTD, Pin7, LOW);
			UART_Send_String("buzzer off");
			UART_Send_String("\r\n");
			
		Delay_ms(100);
		}
		// Convert float to integers (multiply by 1000 to preserve 3 decimal places)
		int32_t vout_int = (int32_t)(VOUT * 1000);
		int32_t rs_int = (int32_t)(RS * 1000);
		int32_t ppm_int = (int32_t)(PPM * 1000);
		char adc_str[20];
		char vout_str[30];
		char rs_str[30];
		char ppm_str[30];

		snprintf(adc_str, sizeof(adc_str), "ADC:%4u", adc_value);
		snprintf(vout_str, sizeof(vout_str), "VOUT: %ld.%03ld V", vout_int / 1000, vout_int % 1000);
		snprintf(rs_str, sizeof(rs_str), "RS: %ld.%03ld Ohm", rs_int / 1000, rs_int % 1000);
        snprintf(ppm_str, sizeof(ppm_str), "PPM:%ld.%03ld",ppm_int / 1000, ppm_int % 1000);
		//prints results
		UART_Send_String(adc_str);
		UART_Send_String("\r\n");

		UART_Send_String(vout_str);
		UART_Send_String("\r\n");

		UART_Send_String(rs_str);
		UART_Send_String("\r\n");
		
		UART_Send_String(ppm_str);
		UART_Send_String("\r\n");
       //prints results on lcd
		Delay_ms(100);
		LCD_setCursor(0, 0);
		LCD_print(adc_str);
		Delay_ms(2000);
		LCD_clear();
		LCD_setCursor(0, 0);
		LCD_print(rs_str);
		Delay_ms(2000);
		LCD_clear();
	    LCD_setCursor(0, 0);
	    LCD_print(ppm_str);
	   Delay_ms(2000);
	   LCD_clear();
	   
}

}
  
