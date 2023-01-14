#include "stm32f10x.h"
#include "delay.h"





void TIM2_Delay500MS(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseSuructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	TIM_TimeBaseSuructure.TIM_Prescaler=35999;
	TIM_TimeBaseSuructure.TIM_Period=999;
	TIM_TimeBaseSuructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseSuructure);
	TIM_ClearFlag(TIM2,TIM_FLAG_Update);
	TIM_Cmd(TIM2,ENABLE);
	while(TIM_GetFlagStatus(TIM2,TIM_FLAG_Update)==RESET);
}


void TIM2_Delay10MS(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseSuructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	TIM_TimeBaseSuructure.TIM_Prescaler=720;
	TIM_TimeBaseSuructure.TIM_Period=999;
	TIM_TimeBaseSuructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseSuructure);
	TIM_ClearFlag(TIM2,TIM_FLAG_Update);
	TIM_Cmd(TIM2,ENABLE);
	while(TIM_GetFlagStatus(TIM2,TIM_FLAG_Update)==RESET);
}
