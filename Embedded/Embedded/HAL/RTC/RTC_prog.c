/*
 * RTC_prog.c
 *
 * Created: 5/21/2025 11:57:46 PM
 *  Author: kareem
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "RTC_interface.h"
#include "../../MCAL/TWI/TWI_interface.h"

#define DS3232_ADDRESS      0x68
#define DS3232_REG_TIME     0x00

static u8 BCD_to_Dec(u8 bcd)
{
	return ((bcd >> 4) * 10) + (bcd & 0x0F);
}

void DS3232_voidGetDateTime(RTC_TimeDate* time)
{
		
		
		TWI_TWI_ErrSendStartCondition();
		TWI_TWI_ErrMasterSendSlaveAddressWithWrite(0x68);
		TWI_TWI_ErrMasterSendData(0x00);
		TWI_TWI_ErrSendRepeatedStart();
		TWI_TWI_ErrMasterSendSlaveAddressWithRead(0x68);

	u8 buffer[7];
	for (u8 i = 0; i < 7; i++) {
		TWI_TWI_ErrMasterReciveData(&buffer[i]);
	}
	TWI_TWI_ErrMasterReciveLastData(&buffer[6]); // NACK
	TWI_voidSendStopCondition();
	
	time->seconds = BCD_to_Dec(buffer[0]);
	time->minutes = BCD_to_Dec(buffer[1]);
	time->hours   = BCD_to_Dec(buffer[2] & 0x3F);  // 24-hour mode
	time->day     = BCD_to_Dec(buffer[3]);
	time->date    = BCD_to_Dec(buffer[4]);
	time->month   = BCD_to_Dec(buffer[5] & 0x1F);  // Ignore century bit
	time->year    = BCD_to_Dec(buffer[6]);
}
