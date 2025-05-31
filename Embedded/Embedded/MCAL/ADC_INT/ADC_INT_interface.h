/*
 * ADC_INT_interface.h
 *
 * Created: 3/13/2025 1:12:29 AM
 *  Author: Kareem
 */ 


#ifndef ADC_INT_INTERFACE_H_
#define ADC_INT_INTERFACE_H_
#include "../../LIB/STD_TYPES.h"

#define ADC0 	0
#define ADC1 	1
#define ADC2 	2
#define ADC3 	3
#define ADC4 	4
#define ADC5 	5
#define ADC6 	6
#define ADC7 	7
extern void ADC_INT_voidInit(void);

extern void ADC_voidStartConversion(u8 copy_u8channel);

extern u16 ADC_u16_intmap(u16 input,u16 input_min,u16 input_max,u16 output_min,u16 output_max);
void ADC_voidSetCallback(void (*ptr)(u16));
#define ADC_MAX_VAL  5

#define ADC_EXTERNAL_REFAVCC_REFS1_REFS0    1
#define ADC_INTERNAL_2_56V_R_REFS1_REFS0    3
#define ADEN_PIN  7
#define ADSC_PIN  6
#define ADIE_PIN  3


#define  ADC_2_PRESCALER          1
#define  ADC_4_PRESCALER          2
#define  ADC_8_PRESCALER          3
#define  ADC_16_PRESCALER         4
#define  ADC_32_PRESCALER         5
#define  ADC_64_PRESCALER         6
#define  ADC_128_PRESCALER        7

#define  ADC_PRESCALER   ADC_128_PRESCALER



#endif /* ADC_INT_INTERFACE_H_ */