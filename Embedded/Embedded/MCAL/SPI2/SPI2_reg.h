/*
 * SPI2_reg.h
 *
 * Created: 5/8/2025 9:25:58 PM
 *  Author: kareem
 */ 


#ifndef SPI2_REG_H_
#define SPI2_REG_H_




#define SPDR_REG *((volatile u8*)0x2F)
#define SPSR_REG *((volatile u8*)0x2E)
#define SPCR_REG *((volatile u8*)0x2D)

#endif /* SPI2_REG_H_ */