/*
 * SPI_interface.h
 *
 * Created: 4/12/2025 7:40:19 PM
 *  Author: kareem
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_



void SPI_voidMasterInit();
void SPI_voidSlaveInit();
void SPI_voidMasterSendData(u8 copy_u8data);
u8	 SPI_u8SlaveReciveData();
void SPI_voidSendString(const char* str);
void SPI_voidReceiveString(char* buffer, u8 maxLength);
u8 SPI_u8Transceive(u8 copy_u8Data);
u8 SPI_u8Avilable();
#endif /* SPI_INTERFACE_H_ */