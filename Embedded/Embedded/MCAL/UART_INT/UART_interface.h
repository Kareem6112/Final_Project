/*
 * UART_interface.h
 *
 * Created: 4/11/2025 8:13:15 PM
 *  Author: kareem
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_



void UART_INIT_voidInit(u32 baudRate);
void UART_voidSendAsync(u8 data);
void UART_SetRxCallback(void (*copy_pfRx)(u8));
void UART_SetTxCallback(void (*copy_pfTx)(void));
void UART_voidSendString_INT(const char* str);


#endif /* UART_INTERFACE_H_ */