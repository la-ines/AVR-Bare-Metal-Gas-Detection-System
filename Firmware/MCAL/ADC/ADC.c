#include "ADC.h"

void ADC_Initialize(){
	
/*Selecting voltage reference*/
  ADMUX_Reg &= ADC_VOLTAGE_REF_clr_msk;  
  ADMUX_Reg |= ADC_VOLTAGE_REF_SELECTOR_msk; 
   	
/*Selecting ADC Mode*/
#if ADC_MODE_SELECTOR ==  ADC_MODE_AUTO_TRIGGER  
     SET_Bit(ADCSRA_Reg,5);
	  ADCSRB_Reg &= ADC_AUTO_TRIG_SRC_clr_msk; 
	  ADCSRB_Reg|= ADC_AUTO_TRIG_SRCE_SELECTOR;
#elif ADC_MODE_SELECTOR ==  ADC_MODE_SINGLE_CONVERSION
       CLEAR_Bit(ADCSRA_Reg,5); 
#endif
  
/*Selecting Adjustment*/
#if ADC_ADJUSTEMENT_SELECTOR == ADC_RIGHT_ADJUSTED
       CLEAR_Bit(ADMUX_Reg ,5);
#elif ADC_ADJUSTEMENT_SELECTOR == ADC_LEFT_ADJUSTED
       SET_Bit(ADMUX_Reg ,5);
#endif

	/*Clearing interrupt flag*/
     SET_Bit(ADCSRA_Reg ,4);
	
	/*enabling ADC */
	  SET_Bit(ADCSRA_Reg ,7);
	
}
void ADC_StartConversion(ADC_Channel_types ADC_channel){
	/*select ADC channel*/
	 ADMUX_Reg &= ADC_CHANNEL_SELECTOR_clr_msk; 
	 ADMUX_Reg |= ADC_channel;
	/*ADC start conversion*/
	SET_Bit(ADCSRA_Reg,6); 
	 
}
uint16_t ADC_GetResult(){
	while(GET_Bit(ADCSRA_Reg,6));  

	return ADC_Reg;  // Return the ADC result
}
