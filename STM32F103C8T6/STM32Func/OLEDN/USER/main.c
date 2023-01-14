#include "stm32f10x.h" //STM32头文件
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
	RCC_Configuration(); //系统时钟初始化 

	I2C_Configuration();//I2C初始化
	

	OLED0561_Init(); //OLED初始化
	OLED_DISPLAY_LIT(100);//亮度设置

	OLED_DISPLAY_PIC1();//显示全屏图片
	Delay(50000000); //延时
	OLED_DISPLAY_CLEAR();
	OLED_DISPLAY_8x16_BUFFER(0,"    VonGott "); //显示字符串
	OLED_DISPLAY_8x16_BUFFER(6,"    EtHill  "); //显示字符串

	/*OLED_DISPLAY_16x16(2,2*16,0);//汉字显示	 洋桃电子
	OLED_DISPLAY_16x16(2,3*16,1);
	OLED_DISPLAY_16x16(2,4*16,2);
	OLED_DISPLAY_16x16(2,5*16,3);*/

}
