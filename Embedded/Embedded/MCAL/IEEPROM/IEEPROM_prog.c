/*
 * IEEPROM_prog.c
 *
 * Created: 4/20/2025 3:45:27 PM
 *  Author: kareem
 */ 
#include "../../LIB/STD_TYPES.h"
#include "IEEPROM_reg.h"
#include "IEEPROM_interface.h"
#define F_CPU 16000000UL 
#include <util/delay.h>

// Flag to indicate EEPROM write completion
volatile u8 eepromWriteComplete = 0;

// Synchronous write function
void EEPROM_Write(u16 address, u8 data)
{
    while (EECR_REG & (1 << EEWE_PIN));  // Wait for any previous write to complete
    EEAR_REG = address;                 // Set EEPROM address register
    EEDR_REG = data;                    // Load data into EEPROM data register
    EECR_REG |= (1 << EEMWE_PIN);       // Set EEMWE to enable write
    EECR_REG |= (1 << EEWE_PIN);        // Set EEWE to start write
}

// Synchronous read function
u8 EEPROM_Read(u16 address)
{
    while (EECR_REG & (1 << EEWE_PIN)); // Wait for any previous write to complete
    EEAR_REG = address;                 // Set EEPROM address register
    EECR_REG |= (1 << EERE_PIN);        // Start EEPROM read
    return EEDR_REG;                    // Return the read data
}

// Initialize EEPROM interrupt
void EEPROM_InitInterrupt(void)
{
    EECR_REG |= (1 << EERIE_PIN);       // Enable EEPROM Ready interrupt
}

// Interrupt-based write function
void EEPROM_WriteInterrupt(u16 address, u8 data)
{
    while (EECR_REG & (1 << EEWE_PIN)); // Wait for any previous write to complete
    EEAR_REG = address;                 // Set EEPROM address register
    EEDR_REG = data;                    // Load data into EEPROM data register
    EECR_REG |= (1 << EEMWE_PIN)| (1 << EEWE_PIN);       // Set EEMWE to enable write  From Mohamed Ali the two instructions must be set within the 4 clock cycles in one instructions 
     
      while (!eepromWriteComplete);     // Wait for write completion
    eepromWriteComplete = 0;            // Reset flag
}

// Interrupt-based read function
u8 EEPROM_ReadInterrupt(u16 address)
{
    while (EECR_REG & (1 << EEWE_PIN)); // Wait for any previous write to complete
    EEAR_REG = address;                 // Set EEPROM address register
    EECR_REG |= (1 << EERE_PIN);        // Start EEPROM read
    return EEDR_REG;                    // Return the read data
}

// ISR for EEPROM Ready interrupt
void __vector_17(void) __attribute__((signal));
void __vector_17(void)
{
    eepromWriteComplete = 1;            // Set flag to indicate write completion
}



