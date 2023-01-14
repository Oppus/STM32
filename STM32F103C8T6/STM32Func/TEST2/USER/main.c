#include "stm32f10x.h"

 void Delay(u32 count)
 {
   u32 i=0;
   for(;i<count;i++);
 }
void LED_run_Config(void);

int main(void)
{
	LED_run_Config();
}
	
void LED_run_Config()
 {
  GPIO_InitTypeDef  GPIO_InitStructure;
	 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	   							//ʹ��PA�˿�ʱ��
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_4| GPIO_Pin_3;			    //PA.5,4,3 �˿�����
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	 								//�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;	 								//IO���ٶ�Ϊ2MHz
  GPIO_Init(GPIOA, &GPIO_InitStructure);			     							//��ʼ��GPIOA.5,4,3
  GPIO_SetBits(GPIOA,GPIO_Pin_5 | GPIO_Pin_4 | GPIO_Pin_3);							//PA.5��4��3 �����
  while(1)
	{
	    GPIO_ResetBits(GPIOA,GPIO_Pin_5);
		Delay(3000000);
		GPIO_SetBits(GPIOA,GPIO_Pin_5);
		GPIO_ResetBits(GPIOA,GPIO_Pin_4);
		Delay(3000000);
		GPIO_SetBits(GPIOA,GPIO_Pin_4);
		GPIO_ResetBits(GPIOA,GPIO_Pin_3);
		Delay(3000000);
		GPIO_SetBits(GPIOA,GPIO_Pin_3);
	}
 }