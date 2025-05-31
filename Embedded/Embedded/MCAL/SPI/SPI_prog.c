/*
 * SPI_prog.c
 *
 * Created: 4/12/2025 7:39:58 PM
 *  Author: Kareem
 */ 
#define F_CPU 16000000UL
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "SPI_interface.h"
#include "SPI_reg.h"
#include <util/delay.h>
void SPI_voidMasterInit()
{
	
	SET_BIT(SPCR_REG,4);
	CLR_BIT(SPCR_REG,3);
	CLR_BIT(SPCR_REG,2);
	
		SET_BIT(SPCR_REG,0);
		SET_BIT(SPCR_REG,1); 
		
	SET_BIT(SPCR_REG,6);
	

}
void SPI_voidSlaveInit()
{
		CLR_BIT(SPCR_REG,4);
		CLR_BIT(SPCR_REG,3);
		CLR_BIT(SPCR_REG,2);
		
		SET_BIT(SPCR_REG,6);
		
		
}

void SPI_voidMasterSendData(u8 copy_u8data)
{
	
	SPDR_REG=copy_u8data;
	while (GET_BIT(SPSR_REG, 7) == 0); // Wait for transmission complete 
}

u8	 SPI_u8SlaveReciveData()
{
	while (GET_BIT(SPSR_REG, 7) == 0); // Wait until data is here 
	return SPDR_REG;
}


void SPI_voidSendString(const char* str)
{
	while (*str)
	{
		SPI_voidMasterSendData(*str++);
		_delay_ms(200);
	}
}

void SPI_voidReceiveString(char* buffer, u8 maxLength)
{
	u8 i = 0;
	u8 ch = 0;
	while (i < (maxLength - 1))
	{
		ch = SPI_u8SlaveReciveData();
		if (ch == '\n' || ch == '\r') break;
		buffer[i++] = ch;
	}
	buffer[i] = '\0';
}

u8 SPI_u8Transceive(u8 copy_u8Data)
{
	// Load data into the SPI data register
	SPDR_REG = copy_u8Data;

	// Wait for transmission and reception to complete
	while (GET_BIT(SPSR_REG, 7) == 0);

	// Return the received data
	return SPDR_REG;
}
void SPI_voidSlaveSendPreload(u8 copy_u8data)
{
	while (!GET_BIT(SPSR_REG, 7)); // Wait until previous transfer completes
	SPDR_REG = copy_u8data;
	
}
u8 SPI_u8Avilable()
{
	while (GET_BIT(SPSR_REG,7) == 0) return 1;
	return 0;
}