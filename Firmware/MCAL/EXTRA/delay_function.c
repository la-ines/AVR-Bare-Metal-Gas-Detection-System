
#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
void Delay_ms(uint16_t ms) {
	TCCR1A = 0;                        
	TCCR1B = (1 << WGM12) | (1 << CS11) | (1 << CS10);  
	OCR1A = 250;

	for (uint16_t i = 0; i < ms; i++) {
		TCNT1 = 0;                     
		TIFR1 |= (1 << OCF1A);         
		while (!(TIFR1 & (1 << OCF1A)));  
	}
}
