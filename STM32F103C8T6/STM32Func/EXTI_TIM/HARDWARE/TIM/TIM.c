#include "stm32f10x.h"
#include "TIM.h"
#include "LED.h"

void TIM_Init(void)
{
	TIM_TimeBaseInitTypeDef  TIM_BaseStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
		
	TIM_BaseStructure.TIM_Prescaler=36000-1;//��ֵ,Ԥ��Ƶϵ�����ƶ�ʱ��������
	TIM_BaseStructure.TIM_Period=1000-1;//��ֵ���Զ���װ��ֵ��С���Ƽ�������
	//TIM_BaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_BaseStructure.TIM_CounterMode=TIM_CounterMode_Up;//���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3,&TIM_BaseStructure);
	//TIM_ClearFlag(TIM2,TIM_FLAG_Update);
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE ); //ʹ��ָ����TIM3�ж�,��������ж�
	
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
void TIM3_IRQHandler(void)   //TIM3�ж�
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //���TIM3�����жϷ������
		{
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update  );  //���TIMx�����жϱ�־ 
		LED=!LED;
		}
}
