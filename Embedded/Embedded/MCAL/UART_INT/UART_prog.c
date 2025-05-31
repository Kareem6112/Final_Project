/*
 * UART_prog.c
 *
 * Created: 4/11/2025 8:12:53 PM
 *  Author: kareem
 */ 

#define  F_CPU 16000000UL
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "UART_interface.h"
#include "UART_reg.h"
#include <util/delay.h>

static void (*UART_pfRxCallback)(u8) = null;
static void (*UART_pfTxCallback)(void) = null;

void UART_INIT_voidInit(u32 baudRate)
{
	u16 ubrr = (F_CPU / (16UL * baudRate)) - 1;
	UBRRH_REG = (u8)(ubrr >> 8);
	UBRRL_REG = (u8)ubrr;

	SET_BIT(UCSRB_REG, RXEN_PIN);   // Receiver enable
	SET_BIT(UCSRB_REG, TXEN_PIN);   // Transmitter enable
	SET_BIT(UCSRB_REG, RXCIE_PIN);  // RX interrupt enable
	SET_BIT(UCSRB_REG, TXCIE_PIN);  // TX interrupt enable

	UCSRC_REG = (1 << URSEL_PIN) | (1 << UCSZ1_PIN) | (1 << UCSZ0_PIN); // 8-bit data
}

void UART_voidSendAsync(u8 data)
{
	UDR_REG = data;
}

void UART_SetRxCallback(void (*copy_pfRx)(u8))
{
	UART_pfRxCallback = copy_pfRx;
}

void UART_SetTxCallback(void (*copy_pfTx)(void))
{
	UART_pfTxCallback = copy_pfTx;
}
void UART_voidSendString_INT(const char* str)
{
	while (*str)
	{
		UART_voidSendAsync(*str++);
		_delay_ms(5);
	}
}
// RX Complete Interrupt
void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
	if (UART_pfRxCallback != null)
	{
		UART_pfRxCallback(UDR_REG);
	}
}

// TX Complete Interrupt
void __vector_15(void) __attribute__((signal));
void __vector_15(void)
{
	if (UART_pfTxCallback != null)
	{
		UART_pfTxCallback();
	}
}
