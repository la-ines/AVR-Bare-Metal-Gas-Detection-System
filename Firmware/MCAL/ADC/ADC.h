#ifndef ADC_H_
#define ADC_H_

#include "../MCAL/Bit_Math.h"
#include "ADC_reg.h"
#include "ADC_types.h"
#include "ADC_config.h"


typedef enum{
	ADC_Channel_0,
	ADC_Channel_1,
	ADC_Channel_2,
	ADC_Channel_3,
	ADC_Channel_4,
	ADC_Channel_5,
	ADC_Channel_6,
	ADC_Channel_7
	}ADC_Channel_types;

void ADC_Initialize(void);
void ADC_StartConversion(ADC_Channel_types ADC_channel);
uint16_t ADC_GetResult(void);




#endif /* ADC_H_ */
