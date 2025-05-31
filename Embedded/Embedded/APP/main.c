/************************************************************************************************************************/
/*
 * main.c
 *
 * Created: 4/19/2025 1:58:25 PM
 *  Author: kareem
 */ 
#include "main.h"
#define MAX 10	
	 u8 pasword[5]={0};
		  u8 count=0;
		  u8 state=0;
		  u8 password_iteration=0;
		  u8 Erorr_number=0;
		  u8 user_number=0;
		  u8 global=0;
		  u8 user_name=0;
		  u8 optimal=0;
typedef enum{ Reg , login,nothing,Delete, Run_time}Case;
		 Case condition=nothing;
typedef struct pass
{
	char name[5];
	u8 number[10];
}Pass;
Pass arr[MAX];
Pass RAM;
void RxHandler(u8 receivedData)
{	
	static u8 loc=0;
	static u8 Reg_counter=0;
	static u8 LOC=0;
	static u8 temp[5];
	if (loc==0)
	{
		if (receivedData =='1')
		{
			condition=login;
			
		}
		else if (receivedData =='2')
		{
			condition=Reg;
			
		}
		else if (receivedData =='3')
		{
			condition=Delete;
			
		}
		loc=1;
		return;
	}
	if (condition != Run_time)
	{
			if(condition==Reg && Reg_counter<5)
			{

				temp[Reg_counter]= receivedData;
				
				LCD_voidSendData(temp[Reg_counter]);
				LOC++;
				Reg_counter++;
				
			}else if(condition==Reg && (Reg_counter>=5 && Reg_counter<=10))
			{
				
				temp[LOC]=  receivedData;
				LCD_voidSendData(temp[LOC]);
				LOC++;
				
				Reg_counter++;
				
			}
			else if(condition==login )
			{
				if (count<5 &&user_name==0)
				{
					
					pasword[count]=receivedData-48;
					RAM.number[count]=pasword[count];
					LCD_voidGotoXY(1,count);
					LCD_voidSendData(receivedData);
					_delay_ms(10);
					LCD_voidGotoXY(1,count);
					LCD_voidSendData('*');
					count++;
					state=0;
				}
				if (count==5 &&user_name==0)
				{
					state=1;
					LCD_voidGotoXY(1,0);
					LCD_voidIntDisplay(state);
					password_iteration++;
					count=0;                             // new
				}
				if (count<5 && user_name==1)
				{

					RAM.name[count]=receivedData;
					LCD_voidGotoXY(1,count);
					LCD_voidSendData(receivedData);
					_delay_ms(10);
					
					count++;
					state=0;
				}
				if (count==5 && user_name==1)
				{
					state=1;
					//count=0;                             // new
				}
			}
			
			
			if (Reg_counter==5)
			{
				for (u8 i=0;i<5;i++)
				{
					arr[user_number].name[i]=temp[i];
				}
				
				LCD_voidSendCommand(LCD_CLEAR_COMMAND);
				LCD_voidSendString("Enter Password");
				LCD_voidGotoXY(1,0);
				LOC=0;
				
			}else if (Reg_counter==10)
			{
				for (u8 i=0;i<5;i++)
				{
					arr[user_number].number[i]=temp[i]-48;
					
				}
				global=1;
			}
	}else if (condition== Run_time)
		{
			//LCD_voidIntDisplay(receivedData-48);
			optimal=receivedData-48;
		}

}

void TxHandler(void)
{
}

u8 check_password(u8 var);
u8 System_enter(u8 var);
void Register(void);
u8 check_username(u8 *ptr);
u8 System_enter_user(u8 *ptr);
void member_delete(void);

int main(void)
{
u8 status=0;
condition ==login;
 u8 key=0;
 TWI_voidMasterInit(0) ; 
 DIO_VoidSetPinDir(DIO_PORTD,DIO_PIN7,OUTPUT); // LED indicator
 DIO_VoidSetPinDir(DIO_PORTD,DIO_PIN6,OUTPUT); // LED indicator
 DIO_VoidSetPinDir(DIO_PORTD,DIO_PIN2,OUTPUT); // LED indicator
 DIO_VoidSetPinDir(DIO_PORTD,DIO_PIN3,OUTPUT); // LED indicator
 DIO_VoidSetPinDir(DIO_PORTD,DIO_PIN4,OUTPUT); // LED Dimmer Circuit
 ADC_voidInit();
 SERVO_voidinit(); // Servo

  
	 LCD_voidInit();
	 
	 
	   
	 KEYPAD_voidInit() ; 

	 GI_voidEnable();
	 UART_INIT_voidInit(9600);
	 UART_SetRxCallback(RxHandler);
	 UART_SetTxCallback(TxHandler);
	 user_number=EEPROM_voidReciveData(103);
	 while(status==0)
	 {
		 LCD_voidGotoXY(0,0);
		 LCD_voidSendString("Login: Press 1");
		 UART_voidSendString_INT("Login: Press 1"); 
		 LCD_voidGotoXY(1,0);
		 LCD_voidSendString("Reg  : Press 2");
		 UART_voidSendString_INT("   Reg  : Press 2"); 
		 LCD_voidGotoXY(3,0);
		 LCD_voidSendString("Delete  : Press 3");
		 UART_voidSendString_INT("   Reg  : Press 3");
		 do
		 {
			 key=KEYPAD_u8GetKey();
			 if (condition != nothing)
			 {
				 break;
			 }
			 	 
		 } while (key==0xff);
		 if(key == '1' ||condition==login)
		 {LCD_voidSendCommand(LCD_CLEAR_COMMAND);LCD_voidSendString("login");UART_voidSendString_INT("login");condition=login; status=1; break;}
		 if(key == '2'||condition==Reg)
		 {LCD_voidSendCommand(LCD_CLEAR_COMMAND);LCD_voidSendString("Register");UART_voidSendString_INT("Register");condition=Reg;status=1; break;}
		 if(key == '3'||condition==Delete)
		 {LCD_voidSendCommand(LCD_CLEAR_COMMAND);LCD_voidSendString("Delete");UART_voidSendString_INT("Delete");condition=Delete;status=1; break;}
	 }
	 
	 for (u8 i=0;i<user_number;i++)
	 {
		 LCD_voidSendCommand(LCD_CLEAR_COMMAND);
		 for (u8 j=0;j<10;j=j+2)
		 {
			 arr[i].name[j/2]=EEPROM_voidReciveData(j+i*20);
		   // LCD_voidSendData(arr[i].name[j/2]);
			
		 }
		  //_delay_ms(1000);
		  //LCD_voidGotoXY(1,0);
		 for (u8 j=10;j<20;j=j+2)
		 {
			 arr[i].number[j/2]=EEPROM_voidReciveData((j)+i*20);
			// LCD_voidIntDisplay(arr[i].number[j/2]);
			
		 }
		//  _delay_ms(100);
	 }
	 
	 if (condition==login)
	 {
		  UART_voidSendString_INT("Hey Enter your password");
		  LCD_voidGotoXY(0,0);
		  LCD_voidSendString("Enter Password");	 
	 }
	 if (condition==Reg)
	 {
		 UART_voidSendString_INT(" Enter user name");
		 LCD_voidGotoXY(0,0);
		 LCD_voidSendString("Enter user name");
		
		 LCD_voidGotoXY(1,0);
	 }
	 if (condition==Delete)
	 {
		 UART_voidSendString_INT(" Delete member");
		 LCD_voidGotoXY(0,0);
		 LCD_voidSendString("Delete member");
		 LCD_voidGotoXY(1,0);
	 }
	u8 count1=0;
	u8 admin=110;
	
	u16 adc_val=0;
	u8  Dimmer_value=0;
	while (1)
	{
		
		if (condition==login)
		{
			if (count1==0)
			{
				user_name=1;
				
				while( !System_enter_user(& admin));
				LCD_voidIntDisplay(admin);
				_delay_ms(500);
				if (admin==0)
				{
					LCD_voidSendString("ADMIN");
					
					_delay_ms(500);
				}
				state=0;
				user_name=0;
				LCD_voidSendCommand(LCD_CLEAR_COMMAND);
				while( !System_enter(admin));

				count1=1;
				LCD_voidSendCommand(LCD_CLEAR_COMMAND);

				
			}
			
		}
		if (condition==Reg &&global==1)
		{
			if (user_number>=10)
			{
				UART_voidSendString_INT("No Maximum Data base");
				LCD_voidSendString("No Maximum Data base");
			}
			UART_voidSendString_INT("enter user name");
			LCD_voidSendCommand(LCD_CLEAR_COMMAND);
			LCD_voidSendString("enter user name");
			Register();
			
			condition =login;	
			
		}
		if (condition==Delete)
		{
			member_delete();
			LCD_voidSendString("OK");
			LCD_voidGotoXY(2,0);
			LCD_voidSendString("number of users:");
			LCD_voidIntDisplay(user_number);
			_delay_ms(1000);
			condition =login;
		}
	
		while((condition==login ||condition==Run_time) && admin ==0)
		{
			LCD_voidGotoXY(0,0);
			LCD_voidSendString("LAMP1:1");
			LCD_voidGotoXY(0,9);
			LCD_voidSendString("LAMP2:2");
			LCD_voidGotoXY(1,0);
			LCD_voidSendString("LAMP3:3");
			LCD_voidGotoXY(1,9);
			LCD_voidSendString("LAMP4:4");
			LCD_voidGotoXY(2,0);
			LCD_voidSendString("Door OPEN:5");
			LCD_voidGotoXY(3,0);
			LCD_voidSendString("Door Close:6");
			LCD_voidGotoXY(3,13);
			LCD_voidSendString("Rest:7");
				adc_val= ADC_u16ReadChannel(ADC3) ;
				adc_val=adc_val-30;
				DCMOTOR_voidInit() ;
				if (adc_val>28)
				{
					DCMOTOR_voidForward(100) ;
				}else DCMOTOR_voidForward(0) ;
				
			_delay_ms(500);
			LCD_voidSendCommand(LCD_CLEAR_COMMAND);

			condition =Run_time;
			while(optimal <10)
			{
				
				if (optimal==1)
				{
					DIO_voidTogglePinVal(DIO_PORTD,DIO_PIN7);
				}else if (optimal==2)
				{
					DIO_voidTogglePinVal(DIO_PORTD,DIO_PIN6);
				}else if (optimal==3)
				{
					DIO_voidTogglePinVal(DIO_PORTD,DIO_PIN2);
				}
				else if (optimal==4)
				{
					DIO_voidTogglePinVal(DIO_PORTD,DIO_PIN3);
				}
				else if (optimal==5)
				{
					SERVO_voidSetAngle(120 ,OCR1A_PIN);
				}
				else if (optimal==6)
				{
					SERVO_voidSetAngle(0 ,OCR1A_PIN);
				}else if (optimal ==7)
				{
					LCD_voidSendCommand(LCD_CLEAR_COMMAND);
					LCD_voidInit();                      // in this line we use the re intilization to fix the LCD  as it goes invalid after 2 intilization
					WDT_voidStart(Time_16_3ms );
					while(1);
				}
				optimal=10;
			}
			_delay_ms(100);
		}
		while((condition==login ||condition==Run_time)&& admin >0)
		{
			LCD_voidGotoXY(0,0);
			LCD_voidSendString("LAMP1:1");
			LCD_voidGotoXY(0,9);
			LCD_voidSendString("LAMP2:2");
			LCD_voidGotoXY(1,0);
			LCD_voidSendString("LAMP3:3");
			LCD_voidGotoXY(1,9);
			LCD_voidSendString("LAMP4:4");
			LCD_voidGotoXY(2,0);
			LCD_voidSendString("Dimmer+:6");
			LCD_voidGotoXY(2,9);
			LCD_voidSendString("Dimmer-:7");
			LCD_voidGotoXY(3,9);
			LCD_voidSendString("Rest:5");
			adc_val= ADC_u16ReadChannel(ADC3) ;
			adc_val=adc_val-30;
			LCD_voidGotoXY(3,0);
			LCD_voidSendString("TEMP= ");
			LCD_voidIntDisplay(adc_val);
			
			DCMOTOR_voidInit() ;
			if (adc_val>28)
			{
				DCMOTOR_voidForward(100) ;
			}else DCMOTOR_voidForward(0) ;
			
			_delay_ms(1000);
			LCD_voidSendCommand(LCD_CLEAR_COMMAND);
			condition =Run_time;
			while(optimal <10)
			{
				if (optimal==1)
				{
					DIO_voidTogglePinVal(DIO_PORTD,DIO_PIN7);
				}else if (optimal==2)
				{
					DIO_voidTogglePinVal(DIO_PORTD,DIO_PIN6);
				}else if (optimal==3)
				{
					DIO_voidTogglePinVal(DIO_PORTD,DIO_PIN2);
				}
				else if (optimal==4)
				{
					DIO_voidTogglePinVal(DIO_PORTD,DIO_PIN3);
				}
				else if (optimal ==5)
				{
					LCD_voidSendCommand(LCD_CLEAR_COMMAND);
					 LCD_voidInit();                      // in this line we use the re Intilization to fix the LCD  as it goes invalid after 2 intilization 
					 WDT_voidStart(Time_16_3ms );
					 while(1);	
				}
				else if (optimal ==6)
				{
					Dimmer_value+=10;
					if (Dimmer_value>=100)Dimmer_value=100;
					TIMER1_void10BitResFastPWM(OCR1B_PIN,Dimmer_value);
				}
				else if (optimal ==7)
				{
					Dimmer_value-=10;
					if (Dimmer_value<0)Dimmer_value=0;
					
					TIMER1_void10BitResFastPWM(OCR1B_PIN,Dimmer_value);
				}
				optimal=10;
			}
			_delay_ms(100);

		}
	}

}
u8 check_password(u8 var)
{
	
u8 correct=0;
LCD_voidSendCommand(LCD_CLEAR_COMMAND);
	if (count==5)
	{	
		
			for (u8 j=0;j<5;j++)
			{	
				if (RAM.number[j]==arr[var].number[j+5])
				{
					
					correct++;
				}
				
			}
			
			
		
		if (correct==5)
		{
			LCD_voidGotoXY(1,0);
			LCD_voidSendString("Right");
			_delay_ms(1000);
			correct=0;
			return 1;
		}else
		{
			Erorr_number++;
			LCD_voidGotoXY(1,0);
			LCD_voidSendString("Wrong");
			
			_delay_ms(1000);
			LCD_voidSendCommand(LCD_CLEAR_COMMAND);
			LCD_voidSendString("Enter password");
			state=0;
			
			correct=0;
		}
		count=0;
	}
	if (Erorr_number==3)
	{
		LCD_voidSendCommand(LCD_CLEAR_COMMAND);
		LCD_voidSendString("Reset System");
		while(1);
	}
	return 0;
	
}
u8 check_username(u8 *ptr)
{
	u8 correct=0;
	 u8 iteration=0;
	 *ptr=iteration;
	LCD_voidSendCommand(LCD_CLEAR_COMMAND);
	if (count==5)
	{
		for(u8 i=0;i<user_number;i++)
		{
			for (u8 j=0;j<5;j++)
			{
				
				if (RAM.name[j]==arr[i].name[j])
				{
					
					correct++;
				}
			}
			
			if (correct==5)
			{
				break;
			}else correct=0;
			iteration++;
			*ptr=iteration;
			
			
		}
		
		if (correct==5)
		{
			LCD_voidGotoXY(1,0);
			LCD_voidSendString("Right");
			_delay_ms(500);
			correct=0;
			return 1;
		}else
		{
			Erorr_number++;
			LCD_voidGotoXY(1,0);
			LCD_voidSendString("Wrong");
			_delay_ms(500);
			LCD_voidSendCommand(LCD_CLEAR_COMMAND);
			LCD_voidSendString("Enter password");
			state=0;
			
			correct=0;
			
		}
		count=0;
	}
	if (Erorr_number==3)
	{
		LCD_voidSendCommand(LCD_CLEAR_COMMAND);
		LCD_voidSendString("Reset System");
		while(1);
	}
	return 0;
}
void Register(void)
{

	if (global==1)
	{
		
		for (u8 i=0;i<10;i=i+2)
		{
			EEPROM_voidSendData(i+user_number*20,arr[user_number].name[i/2]);
		
			_delay_ms(5);
		}
		for (u8 i=0;i<10;i=i+2)
		{
			EEPROM_voidSendData((i+10)+user_number*20,arr[user_number].number[i/2]);
			
			_delay_ms(5);
		}
		for (u8 i=0;i<10;i=i+2)
		{
			LCD_voidSendData(EEPROM_voidReciveData(i+user_number*20));
		}
		for (u8 i=10;i<20;i=i+2)
		{
			LCD_voidIntDisplay(EEPROM_voidReciveData((i)+user_number*20));
		}
		global=0;
		user_number++;
		EEPROM_voidSendData(103,user_number);
			EEPROM_voidSendData(103,user_number);
	}
}
u8 System_enter(u8 var)
{
	u8 counter=0;
	u8 key=0;
	count=0;
	state=0;
	while(state==0)
	{
		
		LCD_voidSendString("Enter password");
		LCD_voidGotoXY(1,0);
		for (counter=0;counter<5;counter++)
		{
			
			do
			{
				key=KEYPAD_u8GetKey();
				if (state==1)break;
				
			} while (key==0xff);
			
			if (state==1)break;
			LCD_voidGotoXY(1,counter);
			pasword[counter]=key-48;
			RAM.number[counter]=pasword[counter];
			LCD_voidSendData(key);
			_delay_ms(500);
			LCD_voidGotoXY(1,counter);
			LCD_voidSendData('*');
		}
		state=1;
		count=5;
	}


 return check_password(var);

	
}
u8 System_enter_user(u8 *ptr)
{
	u8 counter=0;
	u8 key=0;
	count=0;
	state=0;
	while(state==0)
	{
		LCD_voidSendCommand(LCD_CLEAR_COMMAND);
		LCD_voidSendString("Enter user");
		LCD_voidGotoXY(0,0);
		_delay_ms(1000);
		for (counter=0;counter<5;counter++)
		{
			
			do
			{
				key=KEYPAD_u8GetKey();
				if (state==1)break;
				
			} while (key==0xff);
			
			if (state==1)break;
			LCD_voidGotoXY(1,counter);
			LCD_voidSendData(RAM.name[counter]);
			RAM.name[counter]=key-48;
			LCD_voidSendData(key);
			_delay_ms(500);
			LCD_voidGotoXY(1,counter);
			LCD_voidSendData('*');
		}
		state=1;
		count=5;
	}


	return check_username(ptr);
	
}
void member_delete(void)
{
	user_number--;

	EEPROM_voidSendData(103,user_number);
	EEPROM_voidSendData(103,user_number);
}

/*for (u8 i=0;i<user_number;i++)
				{
					for(u8 J=0;J<10;J=J+2){
						
						LCD_voidSendData( arr[i].number[J/2]);
					}
					LCD_voidGotoXY(0,0);
					_delay_ms(100);
					
				}
				for (u8 i=0;i<user_number;i++)
				{
					for(u8 J=10;J<20;J=J+2){
						
						LCD_voidIntDisplay( arr[i].number[J/2]);
					}
					LCD_voidGotoXY(1,0);
					_delay_ms(100);
					
				}*/
	/*EEPROM_voidSendData(103,0);
	EEPROM_voidSendData(103,0);*/
