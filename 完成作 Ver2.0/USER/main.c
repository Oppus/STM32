#include "stm32f10x.h"
#include "delay.h"
#include "KEY.h"
#include "LED.h"

int main(void)
{
	int key=1;
	
	
	LED0_Config();
	LED_run_Config();
	KEY0();
	delay_init();
	
	while(1)
	{
		while(1)
		{
			key= GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_2);
			if(key==0)
			{
				break;
			}
		}
		while(1)
		{
			GPIO_ResetBits(GPIOA,GPIO_Pin_8);
			delay_ms(600);
			GPIO_SetBits(GPIOA,GPIO_Pin_8);
			delay_ms(600);
			key = GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_2);
			if(key==0)
			{
				break;
			}
		}
	
		while(1)
		{
			GPIO_ResetBits(GPIOA,GPIO_Pin_5);
			delay_ms(600);
			GPIO_SetBits(GPIOA,GPIO_Pin_5);
			GPIO_ResetBits(GPIOA,GPIO_Pin_4);
			delay_ms(600);
			GPIO_SetBits(GPIOA,GPIO_Pin_4);
			GPIO_ResetBits(GPIOA,GPIO_Pin_3);
			delay_ms(600);
			GPIO_SetBits(GPIOA,GPIO_Pin_3);
			key= GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_2);
			if(key==0)
			{
				break;
			}
		}
		
			delay_ms(700);
			
	while(1)
 {
	int pre=0;
	delay_init();
	 
	while(1)
	{
		int states=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_11);
		if(states==0&&pre==1)
		{
			if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7)==0)
			{
				GPIO_SetBits(GPIOA,GPIO_Pin_7);
			}
			else 
			{
				GPIO_ResetBits(GPIOA,GPIO_Pin_7);
			}
		}
		pre=states;
		key= GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_2);
			if(key==0)
			{
				break;
			}
		
	}
	 key= GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_2);
			if(key==0)
			{
				break;
			}
	}
	
		while(1)
		{
			delay_ms(6000);
			key= GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_2);
			if(key==0)
			{
				break;
			}
		}
	
		
	}

}
