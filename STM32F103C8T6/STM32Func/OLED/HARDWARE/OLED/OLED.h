#ifndef __OLED_H
#define __OLED_H

#include "sys.h"
#include "I2C.h"

#define OLED0561_ADD 0x78 //OLED的I2C地址
#define COM 0x00 //OLED指令
#define DAT 0x40 //OLED数据

void OLED0561_Init(void);
void OLED0561_DISPLAY(void); //初始化
void OLED_DISPLAY_ON(void); //开显示
void OLED_DISPLAY_OFF(void); //关显示
void OLED_DISPLAY_LIT(u8 x); //亮度调节
void OLED_DISPLAY_CLEAR(void); //清屏操作
void OLED_DISPLAY_8x16(u8 x,u8 y,u16 w); //显示8*16字符
void OLED_DISPLAY_8x16_BUFFER(u8 row,u8 *str); //显示8*16字符串
void OLED_DISPLAY_PIC1(void);
void OLED_DISPLAY_16x16(u8 x,u8 y,u16 w);

#endif


