/*
 * UART_prog.c
 *
 * Created: 4/5/2025 9:33:46 PM
 *  Author: Kareem Glela
 */ 
#define F_CPU 16000000UL
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "UART_interface.h"
#include "UART_reg.h"

void UART_voidInit(u32 baudRate)
{
	u16 ubrr = (F_CPU / (16UL * baudRate)) - 1;
	UBRRH_REG = (u8)(ubrr >> 8);
	UBRRL_REG = (u8)ubrr;
	//UBRRL=103; FOR 9600 BOUD_RATE
	SET_BIT(UCSRB_REG, RXEN_PIN);  // Enable receiver
	SET_BIT(UCSRB_REG, TXEN_PIN);  // Enable transmitter

	// 8-bit data, 1 stop bit, no parity
	UCSRC_REG = (1 << URSEL_PIN) | (1 << UCSZ1_PIN) | (1 << UCSZ0_PIN);
}

void UART_voidSend(u8 data)
{
	while (!GET_BIT(UCSRA_REG, UDRE_PIN));  // Wait until buffer is empty
	UDR_REG = data;
	while (!GET_BIT(UCSRA_REG, UDRE_PIN)); 
}

u8 UART_u8Receive(void)
{
	while (!GET_BIT(UCSRA_REG, RXC_PIN)); // Wait until data is received
	return UDR_REG;
}

void UART_voidSendString(const char* str)
{
	while (*str)
	{
		UART_voidSend(*str++);
	}
}

void UART_voidReceiveString(char* buffer, u8 maxLength) {
	u8 i = 0;
	char x1;
	char x2;
	char x3;
	u8 ch;
	while (i < (maxLength - 1)) {
		ch = UART_u8Receive();
		if (ch == '\n' || ch == '\r') break;
		buffer[i++] = ch;
	}
	x1=buffer[0];
	x2=buffer[1];
	x3=buffer[2];
	buffer[maxLength-2]=x3;
	buffer[maxLength-3]=x2;
	buffer[maxLength-4]=x1;
	
	buffer[i] = '\0'; // Null-terminate
	
}
void UART_voidSendInt(int num)
{
	if (num == 0)
	{
		UART_voidSend('0');
		return;
	}

	if (num < 0)
	{
		UART_voidSend('-');
		num = -num;
	}

	char buffer[10];
	u8 i = 0;

	// Extract digits in reverse
	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	}

	// Send digits in correct order
	while (i > 0)
	{
		UART_voidSend(buffer[--i]);
	}

	UART_voidSend('\r');
}

u16 UART_u16ReceiveInt(void)
{
	u16 result = 0;
	u8 ch;

	while (1)
	{
		ch = UART_u8Receive();  // should return u8

		if (ch == '\r' || ch == '\n')  // Enter key ends input
		break;

		if (ch >= '0' && ch <= '9')    // Digit check
		{
			result = result * 10 + (ch - '0');
		}

	}

	return result;
}

u8 UART_u16DataAvailable(void)
{
	return (UCSRA_REG & (1 << RXC_PIN));  // Return 1 if data is available, otherwise 0
}



