/*
 * UART_reg.h
 *
 * Created: 4/5/2025 9:34:36 PM
 *  Author: Kareem Glela
 */ 


#ifndef UART_REG_H_
#define UART_REG_H_

#define  UDR_REG       *((volatile u8*)0x2C)
#define  UCSRA_REG     *((volatile u8*)0x2B)
#define  UCSRB_REG	   *((volatile u8*)0x2A)
#define  UCSRC_REG	   *((volatile u8*)0x40)/* this is a shared address */
#define  UBRRL_REG	   *((volatile u8*)0x29)
#define  UBRRH_REG	   *((volatile u8*)0x40)/* this is a shared address */
#endif /* UART_REG_H_ */