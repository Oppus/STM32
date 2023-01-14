#include "stm32f10x.h"
#include "LED.h"
#include "check.h"


void KEY0(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 	    
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;			    
  GPIO_Init(GPIOA, &GPIO_InitStructure);			    
}

