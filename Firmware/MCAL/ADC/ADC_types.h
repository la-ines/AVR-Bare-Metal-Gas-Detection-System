#ifndef ADC_TYPES_H_
#define ADC_TYPES_H_
/*ADC VOLTAGE SELECT USING REFS1 AND REFS0 2 FIRST BITS*/
#define ADC_VOLTAGE_REF_clr_msk          0b00111111  // Mask to clear REFS1 and REFS0
#define ADC_VOLTAGE_REF_AVCC             0b01000000  // AVCC with external capacitor at AREF pin (REFS1:0 = 01)
#define ADC_VOLTAGE_REF_AREF             0b00000000  // External AREF (REFS1:0 = 00)
#define ADC_VOLTAGE_REF_1_1v             0b11000000  // Internal 1.1V reference (REFS1:0 = 11)

/*ADC MODE SELECT */
#define ADC_MODE_AUTO_TRIGGER                 1
#define ADC_MODE_SINGLE_CONVERSION            0    

/*ADC ADJUST SELECT*/
#define ADC_RIGHT_ADJUSTED                    0
#define ADC_LEFT_ADJUSTED                     1

/*ADC PRESCALER SELECT*/
#define ADC_PRESCALER_clr_msk               0b11111000
#define ADC_PRESCALER_2_msk                 0b00000000
#define ADC_PRESCALER_4_msk                 0b00000010
#define ADC_PRESCALER_8_msk                 0b00000011
#define ADC_PRESCALER_16_msk                0b00000100
#define ADC_PRESCALER_32_msk                0b00000101
#define ADC_PRESCALER_64_msk                0b00000110
#define ADC_PRESCALER_128_msk               0b00000111

/*ADC Auto Trigger Select*/
#define ADC_AUTO_TRIG_SRC_clr_msk                    0b00011111 
#define ADC_AUTO_TRIG_SRC_FREE_RUNNING_msk           0b00000000
#define ADC_AUTO_TRIG_SRC_ANALOG_COMP_msk            0b00100000
#define ADC_AUTO_TRIG_SRC_EXITI0_msk                 0b01000000
#define ADC_AUTO_TRIG_SRC_TIMER0_COMP_msk            0b01100000
#define ADC_AUTO_TRIG_SRC_TIMER0_0VF_msk             0b10000000
#define ADC_AUTO_TRIG_SRC_TIMER1_COMP_msk            0b10100000
#define ADC_AUTO_TRIG_SRC_TIMER1_OVF_msk             0b11000000
#define ADC_AUTO_TRIG_SRC_TIMER1_CAPT_msk            0b11100000

/*ADC mask to clear channel*/

#define ADC_CHANNEL_SELECTOR_clr_msk                 0b11100000

#endif /* ADC_TYPES_H_ */
