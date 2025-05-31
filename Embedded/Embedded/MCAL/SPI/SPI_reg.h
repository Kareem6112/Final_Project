/*
 * SPI_reg.h
 *
 * Created: 4/12/2025 7:42:49 PM
 *  Author: kareem
 */ 


#ifndef SPI_REG_H_
#define SPI_REG_H_


#define SPDR_REG *((volatile u8*)0x2F)
#define SPSR_REG *((volatile u8*)0x2E)
#define SPCR_REG *((volatile u8*)0x2D)

#endif /* SPI_REG_H_ */