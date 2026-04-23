
#ifndef GAS_APP_H_
#define GAS_APP_H_



#define V_REF 5.0              // refrence voltage adc
#define R_L 10000.0          //load resistance of adc
#define V_CC 5.0              // Supply voltage (5V)
#define ADC_MAX_VALUE 1023.0    // Maximum ADC value for 10-bit resolution
#define V_REF 5.0             // Reference voltage (5V)            
#define R0   355357.120 // refrence resistance (resistance in clean air)
#define A  116.6020682 //CO2 constant A
#define B  -2.769034857 //CO2 constant B

void GAS_APP(void);


#endif /* GAS_APP_H_ */
