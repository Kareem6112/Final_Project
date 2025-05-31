/*
 * ADC_prog.c
 *
 * Created: 3/8/2025 10:37:48 PM
 *  Author: AMIT
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "ADC_interface.h"
#include "ADC_reg.h"




void ADC_voidInit(void){
	
	/* select reference volt :AVCC with external capacitor at AREF pin */
	   SET_BIT(ADMUX_REG,6) ; 
	   CLR_BIT(ADMUX_REG,7) ; 
	   
	   /*  set adc prescaler */
	
	    ADCSRA_REG &=0b11111000 ; 
		ADCSRA_REG|=ADC_PRESCALER ; 

	/*ADC enable */
	
	SET_BIT(ADCSRA_REG,7) ; 
}


u16 ADC_u16ReadChannel(u8 copy_u8channel){
	
	/* select adc channel */
	ADMUX_REG&=0b11100000 ; 
	ADMUX_REG|=copy_u8channel ; 
	
	/* start conversion */
	SET_BIT(ADCSRA_REG,6) ; 
	
	while(GET_BIT(ADCSRA_REG,4)==1) ; 
	
	
	return ADC_REG ; 
	
	
}
u16 ADC_u16ReadDifferentialINPUTChannel(u8 copy_u8channel)
{
	ADMUX_REG&=0b11100000 ;
	ADMUX_REG|= (copy_u8channel & 0x1F) ;
	
	SET_BIT(ADCSRA_REG,6) ;
	
	while(GET_BIT(ADCSRA_REG,4)==1) ;
	
	
	return ADC_REG ;
}

u16 ADC_u16map(u16 input,u16 input_min,u16 input_max,u16 output_min,u16 output_max)
{
	u16 val=0;
	val=(u16)(((f32)(input-input_min)*(output_max-output_min)/(input_max-input_min))+output_min);
	return val;
}
