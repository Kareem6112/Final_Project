/*
 * TFT_interface.h
 *
 * Created: 5/20/2025 8:27:00 PM
 *  Author: kareem
 */ 


#ifndef TFT_INTERFACE_H_
#define TFT_INTERFACE_H_



// ILI9341 Control Pins (Adjust according to your wiring)
#define ILI9341_DC_PORT PORTC
#define ILI9341_DC_PIN  PC7
#define ILI9341_RST_PORT PORTC
#define ILI9341_RST_PIN  PC4
#define ILI9341_CS_PORT PORTC
#define ILI9341_CS_PIN  PC2

// ILI9341 Basic Commands
#define ILI9341_CMD_RESET 0x01
#define ILI9341_CMD_SLEEP_OUT 0x11
#define ILI9341_CMD_DISPLAY_ON 0x29
#define ILI9341_CMD_MEMORY_WRITE 0x2C
#define ILI9341_CMD_PIXEL_FORMAT_SET 0x3A


void ILI9341_Init(void);
void ILI9341_SendCommand(u8 cmd);
void ILI9341_SendData(u8 data);
void ILI9341_FillScreen(u16 color);
void ILI9341_SetAddressWindow(u16 x0, u16 y0, u16 x1, u16 y1);
void ILI9341_DrawPixel(u16 x, u16 y, u16 color);
void ILI9341_DrawChar(u16 x, u16 y, char c, u16 color, u16 bg, u8 size);
void ILI9341_voidWriteString(u16 x, u16 y, u16 color, u16 bg, u8 size,const char *str);
#endif /* TFT_INTERFACE_H_ */