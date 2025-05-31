/*
 * SPI2_prog.c
 *
 * Created: 5/8/2025 9:25:06 PM
 *  Author: kareem
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "SPI2_reg.h"
#include "SPI2_interface.h"

#define F_CPU 16000000UL
#include <util/delay.h>
void SPI_Init(u8 mode, u8 clockPrescaler) {
	if (mode == SPI_MASTER) {
		
		// Enable SPI, Set as Master, Set Clock Prescaler
		SPCR_REG = (1 << 6) | (1 << 4) | clockPrescaler;
		} else {
	
		// Enable SPI, Set as Slave
		SPCR_REG = (1 << 6);
	}
}

void SPI_Transmit(u8 data) {
	SPDR_REG = data;
	while (!(SPSR_REG & (1 << 7)));
}

u8 SPI_Receive(void) {
	while (!(SPSR_REG & (1 << 7)));
	return SPDR_REG;
}

u8 SPI_Transceive(u8 data) {
	SPDR_REG = data;
	while (!(SPSR_REG & (1 << 7)));
	return SPDR_REG;
}
