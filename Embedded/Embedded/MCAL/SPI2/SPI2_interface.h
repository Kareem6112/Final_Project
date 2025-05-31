/*
 * SPI2_interface.h
 *
 * Created: 5/8/2025 9:25:31 PM
 *  Author: kareem
 */ 


#ifndef SPI2_INTERFACE_H_
#define SPI2_INTERFACE_H_

#define SPI_MASTER 1
#define SPI_SLAVE  0

// SPI Clock Prescaler Options
#define SPI_PRESCALER_4    (0 << SPR0) | (0 << SPR1)
#define SPI_PRESCALER_16   (1 << SPR0) | (0 << SPR1)
#define SPI_PRESCALER_64   (0 << SPR0) | (1 << SPR1)
#define SPI_PRESCALER_128  (1 << SPR0) | (1 << SPR1)

// SPI Driver API
void SPI_Init(u8 mode, u8 clockPrescaler);
void SPI_Transmit(u8 data);
u8 SPI_Receive(void);
u8 SPI_Transceive(u8 data);




#endif /* SPI2_INTERFACE_H_ */