/*
 * Kernel_prog.c
 *
 * Created: 4/26/2025 8:24:40 PM
 *  Author: AMIT
 */ 
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/TIMER0/TIMER0_interface.h"
#include "Kernel_interface.h"



Task_type Task_Arr[TASK_NUM]={{0}} ; 



static void Kernel_voidSchduler(void){
	
	 u8 task_i=0 ; 
	 static u16 count=0 ; 
	 count++ ;  
	
	for (task_i=0 ; task_i< TASK_NUM ; task_i++)
	{
		
		if (count % Task_Arr[task_i].periodicity == 0)
		{
			// call 
			if (Task_Arr[task_i].ptr_task !=0)
			{
				if (Task_Arr[task_i].task_state==1)
				{
					Task_Arr[task_i].ptr_task() ;
				}
			}
			
			
		}

	}
	
}

void Kernel_voidCreatTask(void(*ptr_fun)(void) , u8 periority , u16 periodicity ) {
	
			if (Task_Arr[periority].ptr_task == null)
			{
			   Task_Arr[periority].ptr_task= ptr_fun ;
			   Task_Arr[periority].periodicity=periodicity ;
			   Task_Arr[periority].task_state=Resume;
			}
	
}

void Kernel_voidStartSchduler(void) {
	
	TIMER0_voidInit(TIMER0_OUTCOMPMODE,TIMER0_PRESCALER_64,250) ; 
	
	TIMER0_voidSetCallBack(Kernel_voidSchduler,TIMER0_OUTCOMPMODE) ; 

}

void Kernel_voidDeleteTask(u8 periority)
{
	Task_Arr[periority].ptr_task= null ;
}

void Kernel_voidSusspendTask(u8 periority)
{
	  Task_Arr[periority].task_state=Susspend;
}
void Kernel_voidResumeTask(u8 periority)
{
	  Task_Arr[periority].task_state=Resume;
}