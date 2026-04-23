#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_
/*
*configure the voltage refrence range :
*ADC_VOLTAGE_REF_AVCC
*ADC_VOLTAGE_REF_AREF
*ADC_VOLTAGE_REF_2_56v 
*
*/

#define ADC_VOLTAGE_REF_SELECTOR_msk           ADC_VOLTAGE_REF_AVCC
#define ADC_VOLTAGE_REF_mv                     5000 
#define ADC_MAX_NUMBER_OF_STEPS                1024

/*configure the ADC mode 
* Range :
*ADC_MODE_TRIGGER
*ADC_MODE_SINGLE_CONVERSION
*
*/
#define ADC_MODE_SELECTOR                       ADC_MODE_SINGLE_CONVERSION
/*
*Configure the ADC Adjustement 
*Range:
*ADC_RIGHT_ADJUSTED
*ADC_LEFT_ADJUSTED
*
*/

#define ADC_ADJUSTEMENT_SELECTOR                 ADC_RIGHT_ADJUSTED

/*
*Configure the ADC prescaler
*Range:
* ADC_PRESCALER_2_msk                 
* ADC_PRESCALER_4_msk                
* ADC_PRESCALER_8_msk                 
* ADC_PRESCALER_16_msk              
* ADC_PRESCALER_32_msk                
* ADC_PRESCALER_64_msk               
* ADC_PRESCALER_128_msk   
*/
#define ADC_PRESCALER_SELECTOR_msk              ADC_PRESCALER_128_msk
/*
*Configure the ADC trigger source 
*Range :
 ADC_AUTO_TRIG_SRC_clr_msk                    
 ADC_AUTO_TRIG_SRC_FREE_RUNNING_msk           
 ADC_AUTO_TRIG_SRC_ANALOG_COMP_msk            
 ADC_AUTO_TRIG_SRC_EXITI0_msk                 
 ADC_AUTO_TRIG_SRC_TIMER0_COMP_msk            
 ADC_AUTO_TRIG_SRC_TIMER0_0VF_msk             
 ADC_AUTO_TRIG_SRC_TIMER1_COMP_msk            
 ADC_AUTO_TRIG_SRC_TIMER1_OVF_msk             
 ADC_AUTO_TRIG_SRC_TIMER1_CAPT_msk            
*/
#define ADC_AUTO_TRIG_SRCE_SELECTOR             ADC_AUTO_TRIG_SRC_FREE_RUNNING_msk







#endif /* ADC_CONFIG_H_ */
