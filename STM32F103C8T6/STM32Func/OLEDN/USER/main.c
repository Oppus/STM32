#include "stm32f10x.h" //STM32ͷ�ļ�
#include "SYS.h"


#include "OLED.h"
void Delay(u32 count)
 {
   u32 i=0;
   for(;i<count;i++);
 }
void RCC_Configuration(void);
int main (void)
{
	
	Delay(1000);
	RCC_Configuration(); //ϵͳʱ�ӳ�ʼ�� 

	I2C_Configuration();//I2C��ʼ��
	

	OLED0561_Init(); //OLED��ʼ��
	OLED_DISPLAY_LIT(100);//��������

	OLED_DISPLAY_PIC1();//��ʾȫ��ͼƬ
	Delay(50000000); //��ʱ
	OLED_DISPLAY_CLEAR();
	OLED_DISPLAY_8x16_BUFFER(0,"    VonGott "); //��ʾ�ַ���
	OLED_DISPLAY_8x16_BUFFER(6,"    EtHill  "); //��ʾ�ַ���

	/*OLED_DISPLAY_16x16(2,2*16,0);//������ʾ	 ���ҵ���
	OLED_DISPLAY_16x16(2,3*16,1);
	OLED_DISPLAY_16x16(2,4*16,2);
	OLED_DISPLAY_16x16(2,5*16,3);*/

}
