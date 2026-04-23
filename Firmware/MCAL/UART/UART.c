#include "UART.h"
#include "UART_reg.h"
#define F_CPU 16000000UL

#include <util/delay.h>
#include <avr/io.h>  


void UART_initialize(void){
	UBRR0H_Reg = (BAUD_RATE >> 8); 
	UBRR0L_Reg = BAUD_RATE;
	UCSR0B_Reg = 0x18;  
	UCSR0C_Reg = 0x06; 
}

void UART_Send_Char(uint8_t message){
	while (!(UCSR0A_Reg & 0x20)) 
	{
		//do nothing
	}
	UDR0_Reg = message;	
}

void UART_Send_String(const char* str){
	while (*str) {
		UART_Send_Char(*str++);
	}
}

