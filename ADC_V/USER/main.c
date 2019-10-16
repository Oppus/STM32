#include "stm32f10x.h"
#include <stdio.h>

int fputc(int ch,FILE *f)
{
	while (USART_GetFlagStatus (USART1,USART_FLAG_TC)==RESET);
	USART_SendData(USART1,(uint8_t)ch);
	return ch;
}


void NVIC_Config(void);
void TIM2_Config(void);
void ADC1_Config(void);
void USART1_Config(unsigned int baud);
volatile unsigned char adc1_flag;
volatile unsigned short adc1_value=0xAAA;
volatile float voltage_PB0=1.0;

int main(void)
{
	NVIC_Config();
	TIM2_Config();
	ADC1_Config();
	USART1_Config(115200);
	adc1_flag=0;//ADC1��־λ��0
	
	while(1)
	{
		if(adc1_flag)
		{
			adc1_value=ADC_GetConversionValue(ADC1);//�������һ��ADC1����ͨ��ת�����
			voltage_PB0=(float) adc1_value /4096*3.3;//ת��Ϊ��ѹֵ
			printf("%f\n",voltage_PB0);
			adc1_flag=0;
		}
	 }
}

void NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	
  NVIC_InitStructure.NVIC_IRQChannel =TIM2_IRQn;	
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;					
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								
  NVIC_Init(&NVIC_InitStructure); 
}

void TIM2_Config(void)
{
	TIM_TimeBaseInitTypeDef  TIM_BaseStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
		
	TIM_BaseStructure.TIM_Prescaler=36000-1;//��ֵ,Ԥ��Ƶϵ�����ƶ�ʱ��������
	TIM_BaseStructure.TIM_Period=1000-1;//��ֵ���Զ���װ��ֵ��С���Ƽ�������
	TIM_BaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_BaseStructure.TIM_CounterMode=TIM_CounterMode_Up;//���ϼ���ģʽ
	TIM_TimeBaseInit(TIM2,&TIM_BaseStructure);
	TIM_ClearFlag(TIM2,TIM_FLAG_Update);
	
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE ); //ʹ��ָ����TIM3�ж�,��������ж�
	
	TIM_Cmd(TIM2,ENABLE);
}
void ADC1_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	ADC_InitTypeDef ADC_InitStructure;
	 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	//ʹ��PB�˿�ʱ��
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;			    //LED0-->PB.0�˿�����
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN; 	    //ģ������
  GPIO_Init(GPIOA, &GPIO_InitStructure);			    //��ʼ��GPIOB.0
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);	//ʹ��ADC1ʱ��
	RCC_ADCCLKConfig(RCC_PCLK2_Div6); //����ADCʱ��Ƶ��
	
	ADC_DeInit(ADC1);//��ʼ��ADC1
	ADC_InitStructure.ADC_Mode=ADC_Mode_Independent;//����ģʽ
	ADC_InitStructure.ADC_ScanConvMode=ENABLE;//ʹ��ɨ��ģʽ����ͨ����
	ADC_InitStructure.ADC_ContinuousConvMode=ENABLE;//����ģʽ
	ADC_InitStructure.ADC_NbrOfChannel=1;//1��ADCͨ��
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;	//ת���������������
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;	//ADC�����Ҷ���
	ADC_Init(ADC1, &ADC_InitStructure);	//����ADC_InitStruct��ָ���Ĳ�����ʼ������ADCx�ļĴ���   
	ADC_RegularChannelConfig(ADC1, ADC_Channel_8, 1, ADC_SampleTime_55Cycles5 );	//ADC1,ADCͨ��,����ʱ��Ϊ55.5����	  			    
	ADC_Cmd(ADC1, ENABLE);	//ʹ��ָ����ADC1
	
	ADC_ResetCalibration(ADC1);//ʹ�ܸ�λУ׼  
	while(ADC_GetResetCalibrationStatus(ADC1));//�ȴ���λУ׼����
	ADC_StartCalibration(ADC1);//����ADУ׼
	while(ADC_GetCalibrationStatus(ADC1));//�ȴ�У׼����
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);//ʹ��ָ����ADC1�����ת����������
}

void USART1_Config(unsigned int baud)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
  
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	USART_InitStructure.USART_BaudRate=baud;
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;
	USART_InitStructure.USART_StopBits=USART_StopBits_2;
	USART_InitStructure.USART_Parity=USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	USART_Init(USART1,&USART_InitStructure);
	USART_ClearFlag(USART1,USART_FLAG_TC);
	USART_Cmd(USART1,ENABLE);
}
