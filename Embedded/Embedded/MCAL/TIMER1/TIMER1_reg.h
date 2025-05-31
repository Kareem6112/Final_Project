/*
 * TIMER1_reg.h
 *
 * Created: 3/22/2025 11:00:47 PM
 *  Author: Kareem
 */ 


#ifndef TIMER1_REG_H_
#define TIMER1_REG_H_

#define TCCR1A_REG *((volatile u8*)0x4F)
#define TCCR1B_REG *((volatile u8*)0x4E)
#define TCNT1_REG  *((volatile u16*)0x4C)
#define OCR1A_REG  *((volatile u16*)0x4A)
#define OCR1B_REG  *((volatile u16*)0x48)
#define ICR1_REG   *((volatile u16*)0x46)

#endif /* TIMER1_REG_H_ */
