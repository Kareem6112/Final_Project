/*
 * KEYPAD_prog.c
 *
 * Created: 2/22/2025 8:14:45 PM
 *  Author: AMIT
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "KEYPAD_interface.h"
#include "KEYPAD_config.h"
#include "../../MCAL/DIO/DIO_interface.h"

#ifndef STANDARD_KEYPAD

#if (COL_SIZE == 3)
/*
 * Function responsible for mapping the switch number in the keypad to
 * its corresponding functional number in the proteus for 4x3 keypad
 */
 
u8 KEYPAD_DATA[ROW_SIZE][COL_SIZE]={ {'1','2','+'},
	                                 {'3','4','-'},
									 {'=','0','C'}};
									 
//static u8 KEYPAD_4x3_adjustKeyNumber(u8 button_number);
#elif (COL_SIZE == 4)
/*
 * Function responsible for mapping the switch number in the keypad to
 * its corresponding functional number in the Proteus for 4x4 keypad
 */
 u8 KEYPAD_DATA[ROW_SIZE][COL_SIZE]={ {'7','8','9','/'},
	                                  {'4','5','6','*'},
									  {'1','2','3','-'},
									  {'#','0','=','+'}};
//static u8 KEYPAD_4x4_adjustKeyNumber(u8 button_number);
#endif

#endif /* STANDARD_KEYPAD */





void KEYPAD_voidInit(void){
	
	#if       ROW_SIZE==4
		u8 ROW_ARR[ROW_SIZE]={KEYPAD_R0_PIN,KEYPAD_R1_PIN,KEYPAD_R2_PIN,KEYPAD_R3_PIN} ; 
	#elif     ROW_SIZE==3
		u8 ROW_ARR[ROW_SIZE]={KEYPAD_R0_PIN,KEYPAD_R1_PIN,KEYPAD_R2_PIN} ; 
	#endif
	#if     COL_SIZE ==4
		u8 COL_ARR[COL_SIZE]={KEYPAD_COL0_PIN,KEYPAD_COL1_PIN,KEYPAD_COL2_PIN,KEYPAD_COL3_PIN}; 
	#elif   COL_SIZE==3
		u8 COL_ARR[COL_SIZE]={KEYPAD_COL0_PIN,KEYPAD_COL1_PIN,KEYPAD_COL2_PIN}; 
	#endif
	u8 LOC_in_R=0 ; 
	u8 LOC_in_C=0 ; 
	for (LOC_in_R=0 ; LOC_in_R< ROW_SIZE ; LOC_in_R++)
	{
		
		/* MAKE ROWS ----> INPUT */
		DIO_VoidSetPinDir(KEYPAD_ROW_PORT,ROW_ARR[LOC_in_R],INPUT) ; 
		/* Active pull up resistor */
		DIO_VoidSetPinVal(KEYPAD_ROW_PORT,ROW_ARR[LOC_in_R],HIGH) ; 
	}
	for (LOC_in_C=0 ; LOC_in_C< COL_SIZE ; LOC_in_C++)
	{
		/*make column ----> output */
		DIO_VoidSetPinDir(KEYPAD_COL_PORT,COL_ARR[LOC_in_C],OUTPUT) ; 
		/* set all pins ----> HIGH */
		DIO_VoidSetPinVal(KEYPAD_COL_PORT,COL_ARR[LOC_in_C],HIGH)  ; 
	}	
}


u8 KEYPAD_u8GetKey(void){
	#if       ROW_SIZE==4
		u8 ROW_ARR[ROW_SIZE]={KEYPAD_R0_PIN,KEYPAD_R1_PIN,KEYPAD_R2_PIN,KEYPAD_R3_PIN} ; 
	#elif     ROW_SIZE==3
		u8 ROW_ARR[ROW_SIZE]={KEYPAD_R0_PIN,KEYPAD_R1_PIN,KEYPAD_R2_PIN} ; 
	#endif
	#if     COL_SIZE ==4
		u8 COL_ARR[COL_SIZE]={KEYPAD_COL0_PIN,KEYPAD_COL1_PIN,KEYPAD_COL2_PIN,KEYPAD_COL3_PIN}; 
	#elif   COL_SIZE==3
		u8 COL_ARR[COL_SIZE]={KEYPAD_COL0_PIN,KEYPAD_COL1_PIN,KEYPAD_COL2_PIN}; 
	#endif
		u8 row_in=0 ; 
		u8 col_in=0 ; 
		u8 loc_val =0xff ; 
		for (col_in=0 ; col_in < COL_SIZE ; col_in++)
		{
			
			DIO_VoidSetPinVal(KEYPAD_COL_PORT,COL_ARR[col_in],LOW) ; 
			
			for (row_in=0 ; row_in <ROW_SIZE ; row_in++)
			{
				
				if (DIO_U8ReadPinVal(KEYPAD_ROW_PORT,ROW_ARR[row_in])==0)
				{
					
					loc_val=KEYPAD_DATA[row_in][col_in] ; 
					 while(DIO_U8ReadPinVal(KEYPAD_ROW_PORT,ROW_ARR[row_in])==0); 
					return loc_val ; 
					
					
				}
				
				
			}
			
				DIO_VoidSetPinVal(KEYPAD_COL_PORT,COL_ARR[col_in],HIGH) ; 
			
			
			
		}
			
		
	return loc_val ; 
}
