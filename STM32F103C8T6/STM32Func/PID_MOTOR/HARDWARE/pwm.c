#include "stm32f10x.h"
#include "pwm.h"
#include "key.h"
#include "delay.h"
#include "oled.h"
 void TIM1_PWMInit( int a)
{	

	GPIO_InitTypeDef  GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseSuructure; 
	TIM_OCInitTypeDef  TimOCInitStructure;
	
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO , ENABLE);
  //GPIO_AFIODeInit();
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	    
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;			   
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 	 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
  GPIO_Init(GPIOB, &GPIO_InitStructure);			    
  //GPIO_SetBits(GPIOB,GPIO_Pin_8);


	

	
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	TIM_TimeBaseSuructure.TIM_Prescaler=71;
	TIM_TimeBaseSuructure.TIM_Period=49;
	TIM_TimeBaseSuructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseSuructure);
	
	
	
	
	TimOCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TimOCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;
	TimOCInitStructure.TIM_Pulse=a;
	TimOCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OC4Init(TIM4,&TimOCInitStructure);
	TIM_OC4PreloadConfig(TIM4,TIM_OCPreload_Enable);
	TIM_ARRPreloadConfig(TIM4,ENABLE);
	TIM_Cmd(TIM4,ENABLE);
	TIM_CtrlPWMOutputs(TIM4,ENABLE);
	
}


int c=0;
void PWMQJ(void)
	
{
	
	KEY2_Config();
  KEY1_Config();

	while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)==0||GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)==0)
	{
	 TIM2_Delay500MS();
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)==0)
	{
		c=c+1;
	  TIM1_PWMInit(c);
	}
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)==0)
	{
		c=c-1;
		TIM1_PWMInit(c);
  }
	 OLED_Init();
	 OLED_DISPLAY_LIT(100);
  }
	
	
	
	
	
}

