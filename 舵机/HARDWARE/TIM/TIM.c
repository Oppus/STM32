#include "stm32f10x.h"
#include "TIM.h"

void TIMInit(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_BaseStructure;
	TIM_OCInitTypeDef TimOCInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE);	//使能PA端口时钟，使能复用时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	
	 
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;			    //PA.8端口配置
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 	    //复用推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	    //IO口速度为2MHz
  GPIO_Init(GPIOA, &GPIO_InitStructure);			    //初始化GPIOA.8
	
	TIM_BaseStructure.TIM_Prescaler=1999;//数值,预分频系数控制定时器的周期
	TIM_BaseStructure.TIM_Period=719;//数值，自动重装载值大小控制计数个数
	TIM_BaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_BaseStructure.TIM_CounterMode=TIM_CounterMode_Up;//向上计数模式
	TIM_TimeBaseInit(TIM1,&TIM_BaseStructure);

	TimOCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;//PWM模式1
	TimOCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;//有效电平为高
	TimOCInitStructure.TIM_Pulse=35;
	TimOCInitStructure.TIM_OutputState=TIM_OutputState_Enable;//使能输出
	TIM_OC1Init(TIM1,&TimOCInitStructure);
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);//使能重装载器
	TIM_ARRPreloadConfig(TIM1,ENABLE);
	TIM_Cmd(TIM1, ENABLE); //使能TIM3
	TIM_CtrlPWMOutputs(TIM1,ENABLE);
}

