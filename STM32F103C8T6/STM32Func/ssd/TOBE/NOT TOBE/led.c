#include "stm32f10x.h"
#include "led.h"
#include "delay.h"

void led_Init(void)
{
	GPIO_InitTypeDef  GPIO_Initstructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);	

		
	GPIO_Initstructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Initstructure.GPIO_Pin=GPIO_Pin_6;
	GPIO_Initstructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_Initstructure);
	GPIO_SetBits(GPIOA,GPIO_Pin_6);
	
}


void led_Shan(void)
{
	 while(1)
 {
	
	GPIO_SetBits(GPIOA,GPIO_Pin_6);
	delay_ms(100);
	GPIO_ResetBits(GPIOA,GPIO_Pin_6);
 }
	
	
} 

