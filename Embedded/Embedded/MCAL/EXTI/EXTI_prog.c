/*
 * EXTI_prog.c
 *
 * Created: 3/5/2025 7:32:17 PM
 *  Author: Kareem
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "EXTI_reg.h"
#include "EXTI_interface.h"
#include "../GI/GI_interface.h"
void (*EXTI_PTR[3])(void)= {null};




void EXTI_voidEnableOrDisableInterruptPin(u8 Copy_u8INTNum,u8 Copy_u8EN_DIS)
{
	if(Copy_u8EN_DIS==Enable)
	{
					switch(Copy_u8INTNum)
					{
						case INT0: SET_BIT(GICR_REG,GICR_INT0);break;
						
						case INT1: SET_BIT(GICR_REG,GICR_INT1);break;
						
						case INT2: SET_BIT(GICR_REG,GICR_INT2);break;
					}
	}
	
	if(Copy_u8EN_DIS==Disable)
	{
					switch(Copy_u8INTNum)
					{
						case INT0: CLR_BIT(GICR_REG,GICR_INT0);break;
						
						case INT1:CLR_BIT(GICR_REG,GICR_INT1);break;
						
						case INT2:CLR_BIT(GICR_REG,GICR_INT2);break;
					}
	}
}
void EXTI_voidControlSense(u8 Copy_u8INTNum,u8 Copy_u8Sense)
{
	u8 Loc_u8mask=MCUCR_REG;
	switch(Copy_u8Sense)
	{
		case LOW_LEVEL : 
							switch(Copy_u8INTNum)
							
									{
										case INT0: Loc_u8mask &= INT0_SENSE_MASK;
												   Loc_u8mask |= (LOW_LEVEL_INT01<<MCUCR_ISC01_ISC00_SELECT);
												   MCUCR_REG=Loc_u8mask; 
												   break;
												   /*  Can be done also by this way 
													CLR_BIT(MCUCR_REG,0);
													CLR_BIT(MCUCR_REG,1);
													*/
												  
												   
										case INT1: Loc_u8mask &= INT1_SENSE_MASK;
												   Loc_u8mask |= (LOW_LEVEL_INT01<<MCUCR_ISC11_ISC10_SELECT);
												   MCUCR_REG=Loc_u8mask; 
												   break;
												   /*  Can be done also by this way 
													CLR_BIT(MCUCR_REG,2);
													CLR_BIT(MCUCR_REG,3);
													*/
												   
									} break;
									
		case LOGICAL_CHANGE :
									switch(Copy_u8INTNum)
		
									{
										case INT0:  Loc_u8mask &= INT0_SENSE_MASK;
													Loc_u8mask |= (LOGICAL_CHANGE_INT01<<MCUCR_ISC01_ISC00_SELECT);
													MCUCR_REG=Loc_u8mask; 
													break;
													/*  Can be done also by this way 
													SET_BIT(MCUCR_REG,0);
													CLR_BIT(MCUCR_REG,1);
													*/
													
										case INT1:  Loc_u8mask &= INT1_SENSE_MASK;
													Loc_u8mask |= (LOGICAL_CHANGE_INT01<<MCUCR_ISC11_ISC10_SELECT);
													MCUCR_REG=Loc_u8mask;
													break;
													 /*  Can be done also by this way 
													SET_BIT(MCUCR_REG,2);
													CLR_BIT(MCUCR_REG,3);
													*/
													
									} break;
									
		
		case FALLING_EDGE :
									switch(Copy_u8INTNum)
		
									{
										case INT0:  Loc_u8mask &= INT0_SENSE_MASK;
													Loc_u8mask |= (FALLING_EDGE_INT01<<MCUCR_ISC01_ISC00_SELECT);
													MCUCR_REG=Loc_u8mask; 
													break;
													/*  Can be done also by this way 
													CLR_BIT(MCUCR_REG,0);
													SET_BIT(MCUCR_REG,1);
													*/
													
			
										case INT1:  Loc_u8mask &= INT1_SENSE_MASK;
													Loc_u8mask |= (FALLING_EDGE_INT01<<MCUCR_ISC11_ISC10_SELECT);
													MCUCR_REG=Loc_u8mask; 
													break;
													 /*  Can be done also by this way 
													CLR_BIT(MCUCR_REG,2);
													SET_BIT(MCUCR_REG,3);
													*/
													
										case INT2:  
													 CLR_BIT(MCUCSR_REG,MCUCSR_ISC2_BIT);  
													 break;
									} break;
									
									
									
		case RISING_EDGE :
									switch(Copy_u8INTNum)
		
									{
										case INT0:  Loc_u8mask &= INT0_SENSE_MASK;
													Loc_u8mask |= (RISING_EDGE_INT01<<MCUCR_ISC01_ISC00_SELECT);
													MCUCR_REG=Loc_u8mask; 
													break;
													/*  Can be done also by this way 
													SET_BIT(MCUCR_REG,0);
													SET_BIT(MCUCR_REG,1);
													*/
														
										case INT1:  Loc_u8mask &= INT1_SENSE_MASK;
													Loc_u8mask |= (RISING_EDGE_INT01<<MCUCR_ISC11_ISC10_SELECT);
													MCUCR_REG=Loc_u8mask; 
													break;
													 /*  Can be done also by this way 
													SET_BIT(MCUCR_REG,2);
													SET_BIT(MCUCR_REG,3);
													*/
													 
										case INT2:  
													 SET_BIT(MCUCSR_REG,MCUCSR_ISC2_BIT);  
													 break;
									} break;
	}
}


void EXTI_voidSetCallBack(void (*ptr)(void),u8 copy_u8num){
	
	switch(copy_u8num)
	{
		
		case INT0: EXTI_PTR[0]=ptr; break;
		case INT1: EXTI_PTR[1]=ptr; break;
		case INT2: EXTI_PTR[2]=ptr; break;
	}
}


void __vector_1 (void) __attribute__((signal)); // cancel Linker optimization
void __vector_1 (void)
{

	EXTI_PTR[0]();
}


void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{

	
	EXTI_PTR[1]();
}

void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{

	EXTI_PTR[2]();
	
}