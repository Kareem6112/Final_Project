/*
 * WDT_prog.c
 *
 * Created: 4/4/2025 4:35:29 PM
 *  Author: Kareem Glela
 */ 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "WDT_reg.h"
#include "WDT_interface.h"
void WDT_voidStart(u8 copy_u8time)
{
	SET_BIT(WDTCR_REG,WDE_PIN);
	u8 Loc_u8_mask=WDTCR_REG;
	Loc_u8_mask &= 0xF8;
	Loc_u8_mask |= copy_u8time;
	WDTCR_REG	=	Loc_u8_mask;
}
void WDT_voidStop()
{
	SET_BIT(WDTCR_REG,WDTOE_PIN);
}