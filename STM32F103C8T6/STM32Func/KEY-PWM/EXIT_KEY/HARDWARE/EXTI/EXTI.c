#include "EXTI.h"
#include "stm32f10x.h"
#include "delay.h"
#include "sys.h"
#define LED PAout(8)


void EXTI_Config(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource5);
	EXTI_InitStructure.EXTI_Line=EXTI_Line5;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_InitStructure);
}

void NVIC_Config(void)
{
		NVIC_InitTypeDef NVIC_InitStructure;
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	
  	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;	
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;					
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								
  	NVIC_Init(&NVIC_InitStructure); 
}

void KEYInit(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 	    
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;			    
  GPIO_Init(GPIOA, &GPIO_InitStructure);			    
}


