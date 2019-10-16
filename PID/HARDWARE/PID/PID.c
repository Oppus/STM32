#include "stm32f10x.h"
#include "PID.h"
PIDTypeDef PID1;
void PID_TIM(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef  TIM_BaseStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
		
	TIM_BaseStructure.TIM_Prescaler=arr;//数值,预分频系数控制定时器的周期
	TIM_BaseStructure.TIM_Period=psc;//数值，自动重装载值大小控制计数个数
	TIM_BaseStructure.TIM_CounterMode=TIM_CounterMode_Up;//向上计数模式
	TIM_TimeBaseInit(TIM3,&TIM_BaseStructure);
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE ); //使能指定的TIM3中断,允许更新中断
	
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
	int dSpeed,err;//定义速度增量和当前误差（Δu,e(t))
	err=PIDx->SetSpeed-GetSpeed;//e(t)=设定值-捕获值
	dSpeed=PIDx->Kp*(err-PIDx->last_err)+PIDx->Ki*err+PIDx->Kd*(err-2*PIDx->last_err+PIDx->last_before_err);//增量计算公式
	PIDx->last_before_err=PIDx->last_err;//e(k-2)=e(k-1)
	PIDx->last_err=err;//e(k-1)=e(k)
	return(dSpeed);//返回增量值
}
/*void TIM3_IRQHandler(void) 
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //检查TIM3更新中断发生与否
		{
		 PID1.sum_error+=(PID_Mea(&PID1,PWMSpeed));
		 CRR=PID1.sum_error*K  ;   //CRR为TIM_SetCompare()的参数,K为其二者的比例关系
         PWMSpeed=0; //清零
		 TIM_ClearITPendingBit(TIM3, TIM_IT_Update);  //清除TIMx更新中断标志 
		}
}
	*/