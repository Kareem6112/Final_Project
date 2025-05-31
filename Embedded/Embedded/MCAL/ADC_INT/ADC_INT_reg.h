/*
 * ADC_INT_reg.h
 *
 * Created: 3/13/2025 1:12:50 AM
 *  Author: kareem
 */ 


#ifndef ADC_INT_REG_H_
#define ADC_INT_REG_H_

#define ADMUX_REG         *((volatile u8*)0x27 )
#define ADCSRA_REG        *((volatile u8*)0x26 )
#define ADC_DATA_REG	  *((volatile u16*)0x24)

#endif /* ADC_INT_REG_H_ */