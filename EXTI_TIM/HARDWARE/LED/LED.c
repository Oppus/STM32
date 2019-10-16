#include "stm32f10x.h"
#include "LED.h"

void LED0_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	//使能PA端口时钟
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;			    //LED0-->PA.8端口配置
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	    //推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;	    //IO口速度为2MHz
  GPIO_Init(GPIOA, &GPIO_InitStructure);			    //初始化GPIOA.8
  GPIO_SetBits(GPIOA,GPIO_Pin_8);					    //PA.8输出高
	
	GPIO_ResetBits(GPIOA,GPIO_Pin_8);

}
