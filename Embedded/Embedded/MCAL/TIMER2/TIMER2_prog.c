/*
 * TIMER2.c
 *
 * Created: 3/25/2025 11:28:53 PM
 *  Author: Kareem Glela
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "TIMER2_interface.h"
#include "TIMER2_reg.h"
void (*TIMER2_PTR[2])(void)={null};

void TIMER2_voidInit(u8 copy_u8mode ,u8 copy_u8prescaller)
{
	u8 Loc_u8_mask=TCCR2_REG;
	Loc_u8_mask &= 0xF8;
	TCNT2_REG=0x00;
	OCR2_REG =0x00;
	switch(copy_u8mode)
	{
		case TIMER2_OVERFLOWMODE:
		
		Loc_u8_mask |= copy_u8prescaller;

		TCCR2_REG	=	Loc_u8_mask;
		
		/*Select Mode */
		CLR_BIT(TCCR2_REG,WGM21_PIN);
		CLR_BIT(TCCR2_REG,WGM20_PIN);
		
		/* Enable the Timer over flow Interrupt */
		SET_BIT(TIMSK_REG,TOIE2_PIN);
		TCCR2_REG = TCNT2_VAL;
		break;
		
		case TIMER2_OUTCOMPMODE:
		
		Loc_u8_mask |= copy_u8prescaller;

		TCCR2_REG	=	Loc_u8_mask;
		
		/*Select Mode */
		SET_BIT(TCCR2_REG,WGM21_PIN);
		CLR_BIT(TCCR2_REG,WGM20_PIN);
		
		/* Enable the Timer Clear time on compare match Interrupt (PIE)*/
		SET_BIT(TIMSK_REG,OCIE2_PIN);
		OCR2_REG =OCR2_VAL;
		break;
	}
}

void TIMER2_voidFastPWM(u8 copy_u8prescaller,u8 copy_u8dutycycle){
	
	u8 Loc_u8_mask=TCCR2_REG;
	Loc_u8_mask &= 0xF8;
	Loc_u8_mask |= copy_u8prescaller;
	TCCR2_REG	=	Loc_u8_mask;
	SET_BIT(TCCR2_REG,WGM21_PIN);
	SET_BIT(TCCR2_REG,WGM20_PIN);
	
	SET_BIT(TCCR2_REG,COM21_PIN);
	CLR_BIT(TCCR2_REG,COM20_PIN);
	
	OCR2_REG = (copy_u8dutycycle*2.55);
}

void TIMER2_voidPhasePWM(u8 copy_u8prescaller,u8 copy_u8dutycycle)
{
	u8 Loc_u8_mask=TCCR2_REG;
	Loc_u8_mask &= 0xF8;
	Loc_u8_mask |= copy_u8prescaller;
	TCCR2_REG	=	Loc_u8_mask;
	
	SET_BIT(TCCR2_REG,WGM20_PIN);
	CLR_BIT(TCCR2_REG,WGM21_PIN);
	
	CLR_BIT(TCCR2_REG,COM20_PIN);
	SET_BIT(TCCR2_REG,COM21_PIN);
	OCR2_REG = (copy_u8dutycycle*2.55);
}


void TIMER2_voidSetCallBack(void(*ptr)(void),u8 copy_u8mode)
{
	switch(copy_u8mode)
	{
		case TIMER2_OVERFLOWMODE : TIMER2_PTR[0]=ptr; break;
		case TIMER2_OUTCOMPMODE  : TIMER2_PTR[1]=ptr; break;
	}
}

void __vector_5(void) __attribute__ ((signal)) ;
void __vector_5(void)
{
	if(TIMER2_PTR != null)
	TIMER2_PTR[0]();
}

void __vector_4(void) __attribute__ ((signal)) ;
void __vector_4(void)
{
	if(TIMER2_PTR != null)
	TIMER2_PTR[1]();
}