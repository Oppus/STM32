#include "stm32f10x.h"
#include "TIM.h"
#include "LED.h"

void TIM_Init(void)
{
	TIM_TimeBaseInitTypeDef  TIM_BaseStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
		
	TIM_BaseStructure.TIM_Prescaler=36000-1;//数值,预分频系数控制定时器的周期
	TIM_BaseStructure.TIM_Period=1000-1;//数值，自动重装载值大小控制计数个数
	//TIM_BaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_BaseStructure.TIM_CounterMode=TIM_CounterMode_Up;//向上计数模式
	TIM_TimeBaseInit(TIM3,&TIM_BaseStructure);
	//TIM_ClearFlag(TIM2,TIM_FLAG_Update);
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE ); //使能指定的TIM3中断,允许更新中断
	
	TIM_Cmd(TIM3,ENABLE);
	//while (TIM_GetFlagStatus(TIM2,TIM_FLAG_Update)==RESET);
}

void NVIC_Config(void)
{
		NVIC_InitTypeDef NVIC_InitStructure;
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	
  	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;	
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;					
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								
  	NVIC_Init(&NVIC_InitStructure); 
}
void TIM3_IRQHandler(void)   //TIM3中断
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //检查TIM3更新中断发生与否
		{
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update  );  //清除TIMx更新中断标志 
		LED=!LED;
		}
}
