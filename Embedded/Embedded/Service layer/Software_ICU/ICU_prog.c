/*
 * INCU_prog.c
 *
 * Created: 4/4/2025 6:09:39 PM
 *  Author: Kareem Glela
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/TIMER1/TIMER1_interface.h"
#include "../../MCAL/EXTI/EXTI_interface.h"
#include "../../MCAL/GI/GI_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "ICU_interface.h"

u16 Ton_ICU;
u16 Ttotal_ICU;

void ICU_void(void)
{

	static u8 count = 0;
	count++;
	
	
	//TIMER1_voidOVModeInit();   // timer1 for counting in overflow mode 
	
	static u8 init=0;
	init++;
	if (init==1)
	{
		TIMER1_voidOVModeInit();   // timer1 for counting in overflow mode 
	}
	
	if (count == 1)
	{
		
		TIMER1_voidResetVal();  // Reset Timer1 at the first rising edge
		EXTI_voidControlSense(INT0, FALLING_EDGE_INT01);
		
	}
	else if (count == 2)
	{
		
		Ton_ICU = TIMER1_u16ReadVal();  // Capture Ton
		
		
		EXTI_voidControlSense(INT0, RISING_EDGE_INT01);
	}
	else if (count == 3)
	{
		Ttotal_ICU = TIMER1_u16ReadVal();  // Capture the total period
		
		count = 0;  // Reset for the next cycle
	}

}
void ICU_voidInit(u8 copy_u8Intpin)
{

		
		GI_voidEnable();
		EXTI_voidControlSense(copy_u8Intpin, RISING_EDGE_INT01);
		EXTI_voidEnableOrDisableInterruptPin(copy_u8Intpin, Enable);
		EXTI_voidSetCallBack(ICU_void, copy_u8Intpin);
		
}
void ICU_voidParameters(u16* copy_u8TON, u16* copy_u8Ttotal)
{
		*copy_u8TON=Ton_ICU;
		*copy_u8Ttotal=Ttotal_ICU;
}