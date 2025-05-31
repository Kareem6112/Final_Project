/*
 * UART_reg.h
 *
 * Created: 4/11/2025 8:13:32 PM
 *  Author: kareem
 */ 


#ifndef UART_REG_H_
#define UART_REG_H_


// Register Definitions (for ATmega32)
#define UDR_REG      (*((volatile u8*)0x2C))
#define UCSRA_REG    (*((volatile u8*)0x2B))
#define UCSRB_REG    (*((volatile u8*)0x2A))
#define UCSRC_REG    (*((volatile u8*)0x40))
#define UBRRL_REG    (*((volatile u8*)0x29))
#define UBRRH_REG    (*((volatile u8*)0x40))

// Bit Positions in UCSRA
#define RXC_PIN      7
#define UDRE_PIN     5

// Bit Positions in UCSRB
#define RXCIE_PIN    7
#define TXCIE_PIN    6
#define RXEN_PIN     4
#define TXEN_PIN     3

// Bit Positions in UCSRC
#define URSEL_PIN    7
#define UCSZ1_PIN    2
#define UCSZ0_PIN    1

#endif /* UART_REG_H_ */