#include "stm32f10x.h"
#include "GPIO.h"
#include "TIM.h"

void KEYInit(void);
void TIMInit(void);


int main(void)
{
	int paulse=200;
	TIMInit();
	KEYInit();
	while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)==0)
		{
			paulse+=10;
			if (paulse>=900)
				paulse=0;
		}
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)==0)
		{
			paulse-=10;
		if (paulse<=0)
				paulse=0;
		}
		TIM_SetCompare2(TIM3,paulse);
	}
}

void KEYInit(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 	    
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6;			    
  GPIO_Init(GPIOA, &GPIO_InitStructure);			    
}

void TIMInit(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_BaseStructure;
	TIM_OCInitTypeDef TimOCInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO, ENABLE);	//ʹ��PB�˿�ʱ�ӣ�ʹ�ܸ���ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE); //Timer3������ӳ��  TIM3_CH2->PB5    

	 
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;			    //PB.5�˿�����
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 	    //�����������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	    //IO���ٶ�Ϊ50MHz
  GPIO_Init(GPIOA, &GPIO_InitStructure);			    //��ʼ��GPIOB.5
	
	TIM_BaseStructure.TIM_Prescaler=359;//��ֵ,Ԥ��Ƶϵ�����ƶ�ʱ��������
	TIM_BaseStructure.TIM_Period=999;//��ֵ���Զ���װ��ֵ��С���Ƽ�������
	TIM_BaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_BaseStructure.TIM_CounterMode=TIM_CounterMode_Up;//���ϼ���ģʽ
	TIM_TimeBaseInit(TIM1,&TIM_BaseStructure);

	TimOCInitStructure.TIM_OCMode=TIM_OCMode_PWM2;//PWMģʽ2
	TimOCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;//��Ч��ƽΪ��
	TimOCInitStructure.TIM_Pulse=200;
	TimOCInitStructure.TIM_OutputState=TIM_OutputState_Enable;//ʹ�����
	TIM_OC1Init(TIM3,&TimOCInitStructure);
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);//ʹ����װ����
	TIM_ARRPreloadConfig(TIM3,ENABLE);
	TIM_Cmd(TIM3, ENABLE);
	TIM_CtrlPWMOutputs(TIM3,ENABLE);
}
