#include "stm32f10x.h" 

void LED0_Config(void);
void LED0_On(void);
void LED0_Off(void);
void TIM2_Delay500MS(void);
int main(void)
{
	LED0_Config();
	while(1)
	{
		LED0_On();
		TIM2_Delay500MS();
		LED0_Off();
		TIM2_Delay500MS();
	}	
}
	
void LED0_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	//ʹ��PA�˿�ʱ��
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;			    //LED0-->PA.8�˿�����
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	    //�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;	    //IO���ٶ�Ϊ2MHz
  GPIO_Init(GPIOA, &GPIO_InitStructure);			    //��ʼ��GPIOA.8

}
void LED0_On(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_8);
}

void LED0_Off(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_8);
}
void TIM2_Delay500MS()
{
	TIM_TimeBaseInitTypeDef  TIM_BaseStructure;
	RCC_APB2PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
		
	TIM_BaseStructure.TIM_Prescaler=36000-1;//��ֵ,Ԥ��Ƶϵ�����ƶ�ʱ��������
	TIM_BaseStructure.TIM_Period=1000-1;//��ֵ���Զ���װ��ֵ��С���Ƽ�������
	TIM_BaseStructure.TIM_CounterMode=TIM_CounterMode_Up;//���ϼ���ģʽ
	TIM_TimeBaseInit(TIM2,&TIM_BaseStructure);
	TIM_ClearFlag(TIM2,TIM_FLAG_Update);
	TIM_Cmd(TIM2,ENABLE);
	while(TIM_GetFlagStatus(TIM2,TIM_FLAG_Update)==RESET);
}

