/*
 * GI_prog.c
 *
 * Created: 3/5/2025 7:24:29 PM
 *  Author: Kareem
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "GI_reg.h"
#include "GI_interface.h"

void GI_voidEnable(void)
{
	SET_BIT(SREG_REG,GI_Pin);
	//__asm volatile("SEI");
}
void GI_voidDisable(void)
{
		CLR_BIT(SREG_REG,GI_Pin);
		//__asm volatile("CLI");
}