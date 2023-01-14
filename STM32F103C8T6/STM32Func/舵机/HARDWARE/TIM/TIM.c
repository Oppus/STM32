#include "stm32f10x.h"
#include "TIM.h"

void TIMInit(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_BaseStructure;
	TIM_OCInitTypeDef TimOCInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE);	//ʹ��PA�˿�ʱ�ӣ�ʹ�ܸ���ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	
	 
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;			    //PA.8�˿�����
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 	    //�����������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	    //IO���ٶ�Ϊ2MHz
  GPIO_Init(GPIOA, &GPIO_InitStructure);			    //��ʼ��GPIOA.8
	
	TIM_BaseStructure.TIM_Prescaler=1999;//��ֵ,Ԥ��Ƶϵ�����ƶ�ʱ��������
	TIM_BaseStructure.TIM_Period=719;//��ֵ���Զ���װ��ֵ��С���Ƽ�������
	TIM_BaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_BaseStructure.TIM_CounterMode=TIM_CounterMode_Up;//���ϼ���ģʽ
	TIM_TimeBaseInit(TIM1,&TIM_BaseStructure);

	TimOCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;//PWMģʽ1
	TimOCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;//��Ч��ƽΪ��
	TimOCInitStructure.TIM_Pulse=35;
	TimOCInitStructure.TIM_OutputState=TIM_OutputState_Enable;//ʹ�����
	TIM_OC1Init(TIM1,&TimOCInitStructure);
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);//ʹ����װ����
	TIM_ARRPreloadConfig(TIM1,ENABLE);
	TIM_Cmd(TIM1, ENABLE); //ʹ��TIM3
	TIM_CtrlPWMOutputs(TIM1,ENABLE);
}

