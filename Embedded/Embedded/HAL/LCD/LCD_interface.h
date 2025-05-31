/*
 * LCD_interface.h
 *
 * Created: 2/18/2025 7:13:34 PM
 *  Author: Kareem
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define  LCD_4BITMODE         0
#define  LCD_8BITMODE         1 
#define  LCD_MODE             LCD_4BITMODE 

#define LCD_CLEAR_COMMAND                    0x01
#define LCD_GO_TO_HOME                       0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE        0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32
#define LCD_CURSOR_OFF                       0x0C
#define LCD_CURSOR_ON                        0x0E
#define LCD_SET_CURSOR_LOCATION              0x80
#define LCD_DisplayON_Blinking_Cursor	     0x0F

void LCD_voidInit(void) ;
void LCD_voidSendCommand(u8 copy_u8command) ;
void LCD_voidSendData( u8 copy_u8data) ;
void LCD_voidSendString(const char* str);
void LCD_voidGotoXY(u8 row,u8 col);
void LCD_voidLcdClear(void);
void LCD_voidGotoRowColString(u8 copy_u8row,u8 copy_u8col,const char*str);
void LCD_voidIntDisplay(u16 copy_u8int);
void LCD_voidDrawData(u8 copy_u8pattern,u8 data[],u8 copy_u8x,u8 copy_u8y);
void LCD_SendFloat(f32 num, u8 decimal_places);

#endif /* LCD_INTERFACE_H_ */