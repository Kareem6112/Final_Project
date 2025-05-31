
/*
 * TIMER1_prog.c
 *
 * Created: 3/22/2025 11:01:03 PM
 *  Author: Kareem
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "TIMER1_interface.h"
#include "TIMER1_reg.h"
void TIMER1_void10BitResFastPWM(u8 copy_u8pin,u8 copy_u8duty)
{
	u8 Loc_u8_mask=TCCR1B_REG;
	Loc_u8_mask &= 0xF8;
	Loc_u8_mask |= TIMER1_PRESCALER;
	TCCR1B_REG	=	Loc_u8_mask;
	
	/*FastPWM 10Bit resolution*/
	SET_BIT(TCCR1A_REG,WGM10_PIN);
	SET_BIT(TCCR1A_REG,WGM11_PIN);
	SET_BIT(TCCR1B_REG,WGM12_PIN);
	CLR_BIT(TCCR1B_REG,WGM13_PIN);
	switch(copy_u8pin)
	{
		case OC1A_PIN :
				SET_BIT(TCCR1A_REG,COM1A1_PIN);
				CLR_BIT(TCCR1A_REG,COM1A0_PIN);
				OCR1A_REG= (copy_u8duty*10.23);
		break;
		case OC1B_PIN :
				SET_BIT(TCCR1A_REG,COM1B1_PIN);
				CLR_BIT(TCCR1A_REG,COM1B0_PIN);
				OCR1B_REG=(copy_u8duty*10.23);
		break;
	}
	
}

void TIMER1_voidFastPWM_ICR()
{
	u8 Loc_u8_mask=TCCR1B_REG;
	Loc_u8_mask &= 0xF8;
	Loc_u8_mask |= TIMER1_PRESCALER;
	TCCR1B_REG	=	Loc_u8_mask;
	
	CLR_BIT(TCCR1A_REG,WGM10_PIN);
	SET_BIT(TCCR1A_REG,WGM11_PIN);
	SET_BIT(TCCR1B_REG,WGM12_PIN);
	SET_BIT(TCCR1B_REG,WGM13_PIN);
	
	SET_BIT(TCCR1A_REG,COM1A1_PIN);
	CLR_BIT(TCCR1A_REG,COM1A0_PIN);
	
	ICR1_REG=40000;
}
void TIMER1_voidSetOCRVal(u16 copy_u8dutycycle,u8 copy_u8TIM1pin)
{
	switch(copy_u8TIM1pin)
	{
		case OCR1A_PIN :  OCR1A_REG = copy_u8dutycycle;  break;// Set duty cycle
		case OCR1B_PIN :  OCR1B_REG = copy_u8dutycycle;  break; // Set duty cycle
	}
	
}


void TIMER1_voidOVModeInit()
{
	TCCR1A_REG=0x00;
	u8 Loc_u8_mask=TCCR1B_REG;
	Loc_u8_mask &= 0xF8;
	Loc_u8_mask |= TIMER1_PRESCALER;
	TCCR1B_REG	=	Loc_u8_mask;
	TCNT1_REG=0;
}
void TIMER1_voidResetVal()
{
	TCNT1_REG=0x0000;
}
u16 TIMER1_u16ReadVal()
{
	return TCNT1_REG;
}