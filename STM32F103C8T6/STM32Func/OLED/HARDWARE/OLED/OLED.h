#ifndef __OLED_H
#define __OLED_H

#include "sys.h"
#include "I2C.h"

#define OLED0561_ADD 0x78 //OLED��I2C��ַ
#define COM 0x00 //OLEDָ��
#define DAT 0x40 //OLED����

void OLED0561_Init(void);
void OLED0561_DISPLAY(void); //��ʼ��
void OLED_DISPLAY_ON(void); //����ʾ
void OLED_DISPLAY_OFF(void); //����ʾ
void OLED_DISPLAY_LIT(u8 x); //���ȵ���
void OLED_DISPLAY_CLEAR(void); //��������
void OLED_DISPLAY_8x16(u8 x,u8 y,u16 w); //��ʾ8*16�ַ�
void OLED_DISPLAY_8x16_BUFFER(u8 row,u8 *str); //��ʾ8*16�ַ���
void OLED_DISPLAY_PIC1(void);
void OLED_DISPLAY_16x16(u8 x,u8 y,u16 w);

#endif


