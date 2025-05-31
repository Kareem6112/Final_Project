/*
 * IEEPROM_interface.h
 *
 * Created: 4/20/2025 3:46:17 PM
 *  Author: kareem
 */ 


#ifndef IEEPROM_INTERFACE_H_
#define IEEPROM_INTERFACE_H_


// Function prototypes
void EEPROM_Write(u16 address, u8 data);
u8 EEPROM_Read(u16 address);


void EEPROM_InitInterrupt(void);
void EEPROM_WriteInterrupt(u16 copy_u16address, u8 data);
u8 EEPROM_ReadInterrupt(u16 address);

#endif /* IEEPROM_INTERFACE_H_ */