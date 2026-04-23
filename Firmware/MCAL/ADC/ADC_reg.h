#include <stdint.h>
#ifndef ADC_REG_H_
#define ADC_REG_H_


#define ADMUX_Reg        *((volatile uint8_t*)0x7C)
#define ADCSRA_Reg       *((volatile uint8_t*)0x7A)
#define ADCSRB_Reg        *((volatile uint8_t*)0x7B)
#define ADCL_Reg         *((volatile uint8_t*)0x78)
#define ADCH_Reg         *((volatile uint8_t*)0x79)
#define ADC_Reg          *((volatile uint16_t*)0x78)



#endif /* ADC_REG_H_ */
