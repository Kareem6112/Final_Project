/*
 * UART_interface.h
 *
 * Created: 4/5/2025 9:34:06 PM
 *  Author: Kareem
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


#define RXC_PIN		7
#define RXEN_PIN    4
#define TXEN_PIN    3
#define URSEL_PIN	7
#define UCSZ0_PIN	1
#define UCSZ1_PIN	2
#define UCSZ2_PIN	2
#define UDRE_PIN    5
void UART_voidInit(u32 baudRate);
void UART_voidSend(u8 data);
u8   UART_u8Receive(void);
void UART_voidSendString(const char* str);
void UART_voidReceiveString(char* buffer, u8 maxLength); // PLEASE when you use this function the Max length equal the number of character +4 AND WHEN display if the var is rec use it as rec+3 always 
u16 UART_u16ReceiveInt(void);
void UART_voidSendInt(int num);
u8 UART_u16DataAvailable(void);
#endif /* UART_INTERFACE_H_ */