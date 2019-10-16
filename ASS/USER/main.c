#include "stm32f10x.h"
#include <stdio.h>


void TIM_Init(void);
void ADC1_Config(void);
volatile unsigned int adc1_value=200;

int main(void)
{
  TIM_Init();
	ADC1_Config();
	
	
	while(1)
	{
		
			adc1_value=ADC_GetConversionValue(ADC1);//�������һ��ADC1����ͨ��ת�����
			adc1_value=(float)(adc1_value/4096);//ת��Ϊ��ѹֵ
			adc1_value=(int)(adc1_value*50);
			TIM_SetCompare1(TIM1,adc1_value);
			
	 }
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

void TIM_Init(void)
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
	
	TIM_BaseStructure.TIM_Prescaler=359;//��ֵ,Ԥ��Ƶϵ�����ƶ�ʱ��������
	TIM_BaseStructure.TIM_Period=999;//��ֵ���Զ���װ��ֵ��С���Ƽ�������
	TIM_BaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_BaseStructure.TIM_CounterMode=TIM_CounterMode_Up;//���ϼ���ģʽ
	TIM_TimeBaseInit(TIM1,&TIM_BaseStructure);

	TimOCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;//PWMģʽ1
	TimOCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;//��Ч��ƽΪ��
	TimOCInitStructure.TIM_Pulse=200;
	TimOCInitStructure.TIM_OutputState=TIM_OutputState_Enable;//ʹ�����
	TIM_OC1Init(TIM1,&TimOCInitStructure);
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);//ʹ����װ����
	TIM_ARRPreloadConfig(TIM1,ENABLE);
	TIM_Cmd(TIM1, ENABLE); //ʹ��TIM3
	TIM_CtrlPWMOutputs(TIM1,ENABLE);
}
