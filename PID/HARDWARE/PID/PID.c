#include "stm32f10x.h"
#include "PID.h"
PIDTypeDef PID1;
void PID_TIM(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef  TIM_BaseStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
		
	TIM_BaseStructure.TIM_Prescaler=arr;//��ֵ,Ԥ��Ƶϵ�����ƶ�ʱ��������
	TIM_BaseStructure.TIM_Period=psc;//��ֵ���Զ���װ��ֵ��С���Ƽ�������
	TIM_BaseStructure.TIM_CounterMode=TIM_CounterMode_Up;//���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3,&TIM_BaseStructure);
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE ); //ʹ��ָ����TIM3�ж�,��������ж�
	
	TIM_Cmd(TIM3,ENABLE);
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
PIDTypeDef PID1;
void PIDInit(u16 speed)
{

	PID1.SetSpeed=speed;
	PID1.Kp=0;
	PID1.Ki=0;
	PID1.Kd=0;
  PID1.last_err=0;
  PID1.last_before_err=0;
}	
int PID_Mea(PIDTypeDef *PIDx,int GetSpeed)
{
	int dSpeed,err;//�����ٶ������͵�ǰ����u,e(t))
	err=PIDx->SetSpeed-GetSpeed;//e(t)=�趨ֵ-����ֵ
	dSpeed=PIDx->Kp*(err-PIDx->last_err)+PIDx->Ki*err+PIDx->Kd*(err-2*PIDx->last_err+PIDx->last_before_err);//�������㹫ʽ
	PIDx->last_before_err=PIDx->last_err;//e(k-2)=e(k-1)
	PIDx->last_err=err;//e(k-1)=e(k)
	return(dSpeed);//��������ֵ
}
/*void TIM3_IRQHandler(void) 
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //���TIM3�����жϷ������
		{
		 PID1.sum_error+=(PID_Mea(&PID1,PWMSpeed));
		 CRR=PID1.sum_error*K  ;   //CRRΪTIM_SetCompare()�Ĳ���,KΪ����ߵı�����ϵ
         PWMSpeed=0; //����
		 TIM_ClearITPendingBit(TIM3, TIM_IT_Update);  //���TIMx�����жϱ�־ 
		}
}
	*/