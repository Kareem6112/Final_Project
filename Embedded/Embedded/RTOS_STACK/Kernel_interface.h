/*
 * Kernel_interface.h
 *
 * Created: 4/26/2025 8:24:59 PM
 *  Author: AMIT
 */ 


#ifndef KERNEL_INTERFACE_H_
#define KERNEL_INTERFACE_H_

#define  TASK_NUM   3 

typedef struct{
	
	 void(*ptr_task)(void) ; 
	 u16 periodicity ; 
	 u8 task_state;

	
	}Task_type;

#define Susspend 0
#define Resume   1
void Kernel_voidCreatTask(void(*ptr_fun)(void) , u8 periority , u16 periodicity ) ; 

void Kernel_voidStartSchduler(void) ; 


void Kernel_voidDeleteTask(u8 periority);

void Kernel_voidSusspendTask(u8 periority);
void Kernel_voidResumeTask(u8 periority);





#endif /* KERNEL_INTERFACE_H_ */