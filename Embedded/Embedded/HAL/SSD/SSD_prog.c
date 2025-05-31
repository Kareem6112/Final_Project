/*
 * SSD_prog.c
 *
 * Created: 2/18/2025 5:14:31 PM
 *  Author: Kareem
 */ 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "SSD_config.h"
#include "SSD_interface.h"
#if(Mode==1) 
		void SSD_voidInit(void)
		{
			DIO_VoidSetPortDir(Data_Port,OUTPUT);
			DIO_VoidSetPinDir(Enable_Port,Enable_Pin1,OUTPUT);
			DIO_VoidSetPinVal(Enable_Port,Enable_Pin2,HIGH);
		}
		void SSD_voidSendNumber(u8 copy_u8num)
		{
			u8 matrix[]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
	
	
			DIO_VoidSetPortVal(Data_Port,matrix[copy_u8num]);
	
	
		}
#elif(Mode==2) 
		void SSD_voidInit(void)
		{
			DIO_VoidSetPortDir(Data_Port,OUTPUT);
			DIO_VoidSetPinDir(Enable_Port,Enable_Pin1,OUTPUT);
			DIO_VoidSetPinDir(Enable_Port,Enable_Pin2,OUTPUT);
	
		}
		void SSD_voidSendNumber(u8 copy_u8num)
		{
			//u8 matrix[]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
			u8 tens=copy_u8num/10;
			u8 ones=copy_u8num%10;
			DIO_VoidSetPinVal(Enable_Port,Enable_Pin1,HIGH);
			DIO_VoidSetPinVal(Enable_Port,Enable_Pin2,HIGH);
			DIO_VoidSetPortVal(Data_Port,ones| tens<<4);
	
		}

#endif
