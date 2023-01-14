#include "stm32f10x.h" //STM32ͷ�ļ�
#include "OLED.h"
#include "sys.h"

void OLED0561_Init(void);
void OLED0561_DISPLAY(void); //��ʼ��
void OLED_DISPLAY_LIT(u8 x); //���ȵ���
void OLED_DISPLAY_CLEAR(void); //��������
void OLED_DISPLAY_8x16_BUFFER(u8 row,u8 *str); //��ʾ8*16�ַ���
void OLED_DISPLAY_PIC1(void);
void OLED_DISPLAY_16x16(u8 x,u8 y,u16 w);
void RCC_Configuration();
void Delay(u32 count)
 {
   u32 i=0;
   for(;i<count;i++);
 }
int main (void)
{
	
	Delay(5000);
	OLED0561_Init(); //OLED��ʼ��
	RCC_Configuration(); //ϵͳʱ�ӳ�ʼ�� 

	OLED_DISPLAY_LIT(100);//��������

	OLED_DISPLAY_PIC1();//��ʾȫ��ͼƬ
	Delay(50000); //��ʱ
	OLED_DISPLAY_CLEAR();
	OLED_DISPLAY_8x16_BUFFER(0,"   YoungTalk "); //��ʾ�ַ���
	OLED_DISPLAY_8x16_BUFFER(6,"  Temp:"); //��ʾ�ַ���

	OLED_DISPLAY_16x16(2,2*16,0);//������ʾ	 ���ҵ���
	OLED_DISPLAY_16x16(2,3*16,1);
	OLED_DISPLAY_16x16(2,4*16,2);
	OLED_DISPLAY_16x16(2,5*16,3);

	while(1);
}
