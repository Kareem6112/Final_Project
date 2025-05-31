/*
 * EXTI_interface.h
 *
 * Created: 3/5/2025 7:32:37 PM
 *  Author: kareem
 */ 


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


#define INT0_SENSE_MASK 0b11111100
#define INT1_SENSE_MASK 0b11110011

#define LOW_LEVEL      0
#define LOGICAL_CHANGE 1
#define FALLING_EDGE   2
#define RISING_EDGE    3


#define INT0 (u8)0
#define INT1 (u8)1
#define INT2 (u8)2

#define GICR_INT0    (u8)6
#define GICR_INT1    (u8)7
#define GICR_INT2    (u8)5

#define MCUCR_ISC01_ISC00_SELECT  (u8)0
#define MCUCR_ISC11_ISC10_SELECT  (u8)2


#define  Disable 0
#define  Enable  1

#define LOW_LEVEL_INT01      0
#define LOGICAL_CHANGE_INT01 1
#define FALLING_EDGE_INT01   2
#define RISING_EDGE_INT01    3


#define MCUCSR_ISC2_BIT 6

extern  void EXTI_voidEnableOrDisableInterruptPin(u8 Copy_u8INTNum,u8 Copy_u8EN_DIS);

extern void EXTI_voidControlSense(u8 Copy_u8INTNum,u8 Copy_u8Sense); /* This step should be before enable */

extern void EXTI_voidSetCallBack(void (*ptr)(void),u8 copy_u8num);

#endif /* EXTI_INTERFACE_H_ */