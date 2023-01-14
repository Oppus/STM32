#include "stm32f10x.h" //STM32头文件
#include "OLED.h"
#include "sys.h"

void OLED0561_Init(void);
void OLED0561_DISPLAY(void); //初始化
void OLED_DISPLAY_LIT(u8 x); //亮度调节
void OLED_DISPLAY_CLEAR(void); //清屏操作
void OLED_DISPLAY_8x16_BUFFER(u8 row,u8 *str); //显示8*16字符串
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
	OLED0561_Init(); //OLED初始化
	RCC_Configuration(); //系统时钟初始化 

	OLED_DISPLAY_LIT(100);//亮度设置

	OLED_DISPLAY_PIC1();//显示全屏图片
	Delay(50000); //延时
	OLED_DISPLAY_CLEAR();
	OLED_DISPLAY_8x16_BUFFER(0,"   YoungTalk "); //显示字符串
	OLED_DISPLAY_8x16_BUFFER(6,"  Temp:"); //显示字符串

	OLED_DISPLAY_16x16(2,2*16,0);//汉字显示	 洋桃电子
	OLED_DISPLAY_16x16(2,3*16,1);
	OLED_DISPLAY_16x16(2,4*16,2);
	OLED_DISPLAY_16x16(2,5*16,3);

	while(1);
}
