/*
 * ADC_INT_prog.h
 *
 * Created: 3/13/2025 1:13:10 AM
 *  Author: kareem
 */ 


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "ADC_INT_reg.h"
#include "ADC_INT_interface.h"
volatile u16 ADC_DATA=0;
volatile u8  conversion_complete_flag=0;

static void (*ADC_callback)(u16) = null;


void ADC_INT_voidInit()
{
	u8 Loc_u8Admux=ADMUX_REG ;
	u8 Loc_u8ADCSRA=ADCSRA_REG ;
	Loc_u8Admux &=0x3F;
	Loc_u8Admux |=(ADC_EXTERNAL_REFAVCC_REFS1_REFS0<<6);
	ADMUX_REG=Loc_u8Admux;
	
	Loc_u8ADCSRA&=0xF8;
	Loc_u8ADCSRA|=ADC_PRESCALER;
	ADCSRA_REG=Loc_u8ADCSRA;
	
	SET_BIT(ADCSRA_REG,ADEN_PIN);
	SET_BIT(ADCSRA_REG,ADIE_PIN);
	
}

void   ADC_voidStartConversion(u8 copy_u8channel)  // Right function to use with full ADC Interrupt 
{

	u8 Loc_u8Admux=ADMUX_REG ;
	Loc_u8Admux &=0xE0;
	Loc_u8Admux |=copy_u8channel;
	ADMUX_REG= Loc_u8Admux;
	
	SET_BIT(ADCSRA_REG,ADSC_PIN);
	
}

void ADC_voidSetCallback(void (*ptr)(u16))  // Right function to use with full ADC Interrupt 
{
	ADC_callback = ptr;
}

u16 ADC_u16_intmap(u16 input, u16 input_min, u16 input_max, u16 output_min, u16 output_max)
{
	u16 val;
	val= (u16)(((u32)(input - input_min) * (output_max - output_min)) / (input_max - input_min) + output_min);
	return val;
}
void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
	ADC_DATA = ADC_DATA_REG;
	if (ADC_callback != null)
	{
		ADC_callback(ADC_DATA);
	}
}


/*

void __vector_16 (void) __attribute__((signal)); // cancel Linker optimization
void __vector_16 (void)
{
	ADC_DATA=ADC_DATA_REG;
	conversion_complete_flag=1;
}

u16  ADC_u16GetResult()                 // NOT Right function to use with full ADC Interrupt As it contains polling
{
	while(conversion_complete_flag==0);
	conversion_complete_flag=0;
	
	return ADC_DATA;
}
*/