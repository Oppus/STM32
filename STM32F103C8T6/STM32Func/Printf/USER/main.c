#include"stm32f10x.h"
#include <stdio.h>

#define ITM_Port8(n)    (*((volatile unsigned char *)(0xE0000000+4*n)))
#define ITM_Port16(n)   (*((volatile unsigned short*)(0xE0000000+4*n)))
#define ITM_Port32(n)   (*((volatile unsigned long *)(0xE0000000+4*n)))
#define DEMCR           (*((volatile unsigned long *)(0xE000EDFC)))
#define TRCENA          0x01000000

struct __FILE { int handle; /* Add whatever you need here */ };
    FILE __stdout;
    FILE __stdin;
    
int fputc(int ch, FILE *f) 
{
    if (DEMCR & TRCENA) 
    {
        while (ITM_Port32(0) == 0);
        ITM_Port8(0) = ch;
    }
    return(ch);
}
 void Delay(u32 count)
 {
   u32 i=0;
   for(;i<count;i++);
 }
void LED0_Config(void);
int main()
{
	while(1)
	{
		LED0_Config();
		printf("test\n");
	}
}
void LED0_Config(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
	 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	//使能PA端口时钟
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;			    //LED0-->PA.8端口配置
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	    //推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;	    //IO口速度为2MHz
  GPIO_Init(GPIOA, &GPIO_InitStructure);			    //初始化GPIOA.8
  GPIO_SetBits(GPIOA,GPIO_Pin_8);					    //PA.8输出高
  
 
	GPIO_ResetBits(GPIOA,GPIO_Pin_8);
	Delay(3000000);
	GPIO_SetBits(GPIOA,GPIO_Pin_8);
	Delay(3000000);
	GPIO_ResetBits(GPIOA,GPIO_Pin_8);
	Delay(3000000);
	GPIO_SetBits(GPIOA,GPIO_Pin_8);
  
}
