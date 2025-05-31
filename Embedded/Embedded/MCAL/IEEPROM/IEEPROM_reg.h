/*
 * IEEPROM_reg.h
 *
 * Created: 4/20/2025 3:45:46 PM
 *  Author: kareem
 */ 


#ifndef IEEPROM_REG_H_
#define IEEPROM_REG_H_


#define EEAR_REG *((volatile u16*)0x3E)
#define EEDR_REG *((volatile u8*)0x3D)
#define EECR_REG *((volatile u8*)0x3C)

#define EEMWE_PIN   2                  // EEPROM Master Write Enable
#define EEWE_PIN    1                 // EEPROM Write Enable
#define EERE_PIN    0                // EEPROM Read Enable
#define EERIE_PIN   3				//  EEPROM Read INterrupt Enable 

#endif /* IEEPROM_REG_H_ */