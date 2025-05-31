/*
 * TIMER0_prog.c
 *
 * Created: 4/9/2025 2:19:41 PM
 *  Author: kareem
 */ 


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "TIMER0_interface.h"
#include "TIMER0_reg.h"

void (*TIMER_PTR[2])(void)={null};

void TIMER0_voidInit(u8 copy_u8mode ,u8 copy_u8prescaller,u8 copy_preloadval)
{
	u8 Loc_u8_mask=TCCR0_REG;
	Loc_u8_mask &= 0xF8;
	TCNT0_REG=0x00;
	OCR0_REG =0x00;
	switch(copy_u8mode)
	{
		case TIMER0_OVERFLOWMODE:
		
		Loc_u8_mask |= copy_u8prescaller;

		TCCR0_REG	=	Loc_u8_mask;
		
		/*Select Mode */
		CLR_BIT(TCCR0_REG,WGM01_PIN);
		CLR_BIT(TCCR0_REG,WGM00_PIN);
		
		/* Enable the Timer over flow Interrupt */
		SET_BIT(TIMSK_REG,TOIE0_PIN);
		TCNT0_REG = copy_preloadval;
		break;
		
		case TIMER0_OUTCOMPMODE:
		
		Loc_u8_mask |= copy_u8prescaller;

		TCCR0_REG	=	Loc_u8_mask;
		
		/*Select Mode */
		SET_BIT(TCCR0_REG,WGM01_PIN);
		CLR_BIT(TCCR0_REG,WGM00_PIN);
		
		/* Enable the Timer Clear time on compare match Interrupt (PIE)*/
		SET_BIT(TIMSK_REG,OCIE0_PIN);
		OCR0_REG =copy_preloadval;
		break;
	}
}

void TIMER0_voidFastPWM(u8 copy_u8prescaller,u8 copy_u8dutycycle){
	
	u8 Loc_u8_mask=TCCR0_REG;
	Loc_u8_mask &= 0xF8;
	Loc_u8_mask |= copy_u8prescaller;
	TCCR0_REG	=	Loc_u8_mask;
	SET_BIT(TCCR0_REG,WGM01_PIN);
	SET_BIT(TCCR0_REG,WGM00_PIN);
	
	SET_BIT(TCCR0_REG,COM01_PIN);
	CLR_BIT(TCCR0_REG,COM00_PIN);
	
	OCR0_REG = (u8)(copy_u8dutycycle*2.55);
}

void TIMER0_voidPhasePWM(u8 copy_u8prescaller,u8 copy_u8dutycycle)
{
	u8 Loc_u8_mask=TCCR0_REG;
	Loc_u8_mask &= 0xF8;
	Loc_u8_mask |= copy_u8prescaller;
	TCCR0_REG	=	Loc_u8_mask;
	
	SET_BIT(TCCR0_REG,WGM00_PIN);
	CLR_BIT(TCCR0_REG,WGM01_PIN);
	
	CLR_BIT(TCCR0_REG,COM00_PIN);
	SET_BIT(TCCR0_REG,COM01_PIN);
	OCR0_REG = (copy_u8dutycycle*2.55);
}


void TIMER0_voidSetCallBack(void(*ptr)(void),u8 copy_u8mode)
{
	switch(copy_u8mode)
	{
		case TIMER0_OVERFLOWMODE : TIMER_PTR[0]=ptr; break;
		case TIMER0_OUTCOMPMODE  : TIMER_PTR[1]=ptr; break;
	}
}

void __vector_11(void) __attribute__ ((signal)) ;
void __vector_11(void)
{
	if(TIMER_PTR[0] != null)
	TIMER_PTR[0]();
}

void __vector_10(void) __attribute__ ((signal)) ;
void __vector_10(void)
{
	if(TIMER_PTR[1] != null)
	TIMER_PTR[1]();
}