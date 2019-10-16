#include "stm32f10x.h"
#include "led.h"
#include "delay.h"



int main (void)
	
{

	int a=1;
	delay_init();
	led_Init();

	
while(1)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_7);
  delay_ms(600);
	GPIO_SetBits(GPIOA,GPIO_Pin_7);
	delay_ms(600);
	a = GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1);
	if(a==0)
   {
		 break;
	 }
 }

while(1)
 {
 
  GPIO_ResetBits(GPIOA,GPIO_Pin_5);
	delay_ms(600);
	GPIO_SetBits(GPIOA,GPIO_Pin_5);
	
	GPIO_ResetBits(GPIOB,GPIO_Pin_5);
	delay_ms(600);
	GPIO_SetBits(GPIOB,GPIO_Pin_5);
	
	
	GPIO_ResetBits(GPIOB,GPIO_Pin_6);
	delay_ms(600);
	GPIO_SetBits(GPIOB,GPIO_Pin_6);
	 
  a = GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1); 
  if(a==0)
	{
		break;
	}
}
 while(1)
 {
	int pre=0;
	delay_init();
	led_Init();
	
	while(1)
	{
		int states=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8);
		if(states==0&&pre==1)
		{
			if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)==0)
			{
				GPIO_SetBits(GPIOB,GPIO_Pin_8);
			}
			else 
			{
				GPIO_ResetBits(GPIOB,GPIO_Pin_8);
			}
		}
		pre=states;
		
	}
	
	 
	 
	 
 }
	
  

}





