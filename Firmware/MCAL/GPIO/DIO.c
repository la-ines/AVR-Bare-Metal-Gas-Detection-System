#define F_CPU 1600000UL
#include "DIO_reg.h"
#include "DIO_types.h"
#include "Bit_Math.h"
#include "DIO1.h"
#define DIRECTION_OUTPUT 0xFF
#define DIRECTION_INPUT  0x00
#include <util/delay.h>
#include <avr/io.h>  

void DIO_SetPortDirection( DIO_PORT port_ID , DIO_Direction direction){
	if(Output == direction){
		switch(port_ID){
			case DIO_PORTA : *((volatile unsigned char*)0x3A)=0xFF ;break;
			case DIO_PORTB : *((volatile unsigned char*)0x24)=0xFF ;break; 
			case DIO_PORTC : *((volatile unsigned char*)0x27)=0xFF ;break; 
			case DIO_PORTD : *((volatile unsigned char*)0x2A)=0xFF ;break; 
		}
	}
	else if(Input == direction){
		 switch(port_ID){
			case DIO_PORTA :*((volatile unsigned char*)0x3A)=0x00 ; break;
			case DIO_PORTB :*((volatile unsigned char*)0x24)=0x00 ;break;
			case DIO_PORTC : *((volatile unsigned char*)0x27)=0x00 ;break;
			case DIO_PORTD : *((volatile unsigned char*)0x2A)=0x00 ;break;
		}
}
}

void DIO_SetPortValue(DIO_PORT port_ID, unsigned char value){
	if(DIRECTION_OUTPUT == value){
     switch(port_ID){
		case DIO_PORTA : *((volatile unsigned char*)0x3B)=0xFF ;break;
		case DIO_PORTB : *((volatile unsigned char*)0x25)=0xFF ; break;
		case DIO_PORTC : *((volatile unsigned char*)0x28)=0xFF ;break;
		case DIO_PORTD : *((volatile unsigned char*)0x2B)=0xFF ;break;
		
	 }
	}
	 else if(DIRECTION_INPUT == value){
		switch(port_ID){
			case DIO_PORTA : *((volatile unsigned char*)0x3B)=0x00 ;break;
			case DIO_PORTB : *((volatile unsigned char*)0x25)=0x00 ;break;
			case DIO_PORTC : *((volatile unsigned char*)0x28)=0x00 ;break;
			case DIO_PORTD : *((volatile unsigned char*)0x2B)=0x00 ;break;
		}
	
}
}


void DIO_SetPinDirection(DIO_PORT port_ID , Pin_Value pin_ID , DIO_Direction direction ){
	if(port_ID <= DIO_PORTD && pin_ID <= Pin7){
		if(direction == Output){
			switch(port_ID){
				case DIO_PORTA :*((volatile unsigned char*)0x3A)|= (1 << pin_ID );break;
				case DIO_PORTB :*((volatile unsigned char*)0x24)|= (1 << pin_ID );break;
				case DIO_PORTC :*((volatile unsigned char*)0x27)|= (1 << pin_ID );break;
				case DIO_PORTD :*((volatile unsigned char*)0x2A)|= (1 << pin_ID );break;
				
				
				}
		}
		else if(direction == Input){
			switch(port_ID){
				case DIO_PORTA :*((volatile unsigned char*)0x3A)&= ~(1 << pin_ID);break;
				case DIO_PORTB :*((volatile unsigned char*)0x24)&= ~(1 << pin_ID);break;
				case DIO_PORTC :*((volatile unsigned char*)0x27)&= ~(1 << pin_ID);break;
				case DIO_PORTD :*((volatile unsigned char*)0x2A)&= ~(1 << pin_ID);break;
				
			}
			
		}
		
	}
}
	
	
 
void DIO_SetPinValue(DIO_PORT port_ID , Pin_Value pin_ID , DIO_Value value ){
	 if (port_ID <= DIO_PORTD && pin_ID <= Pin7){
		 if(value == HIGH){
				switch(port_ID){
					 case DIO_PORTA: *((volatile unsigned char*)0x3B) |= (1 << pin_ID );break;  
					 case DIO_PORTB: *((volatile unsigned char*)0x25) |= (1 << pin_ID ); break;
					 case DIO_PORTC: *((volatile unsigned char*)0x28) |= (1 << pin_ID );break;
					 case DIO_PORTD: *((volatile unsigned char*)0x2B) |= (1 << pin_ID ); break;
					
				}
		 }
		 else if(value == LOW){
			  switch(port_ID){
				case DIO_PORTA: *((volatile unsigned char*)0x3B) &= ~(1 << pin_ID);break;
				case DIO_PORTB: *((volatile unsigned char*)0x25) &= ~(1 << pin_ID);break;
				case DIO_PORTC: *((volatile unsigned char*)0x28) &= ~(1 << pin_ID);break;
				case DIO_PORTD: *((volatile unsigned char*)0x2B) &= ~(1 << pin_ID);break;
			 
		 }
		 
	 }
}
}

DIO_Value DIO_GetPinValue(DIO_PORT port_ID , Pin_Value pin_ID){
	
	DIO_Value PinValue =0;
	if(port_ID <= DIO_PORTD && pin_ID <= Pin7){
		switch(port_ID){
			case DIO_PORTA: PinValue = ((PINA_Reg >> pin_ID) & 1); break; 
			case DIO_PORTB: PinValue = ((PINB_Reg >> pin_ID) & 1); break;
			case DIO_PORTC: PinValue = ((PINC_Reg >> pin_ID) & 1); break; 
			case DIO_PORTD: PinValue = ((PIND_Reg >> pin_ID) & 1); break;
		}
	}
	return PinValue;
}
