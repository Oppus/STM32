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
		
			adc1_value=ADC_GetConversionValue(ADC1);//返回最近一次ADC1规则通道转换结果
			adc1_value=(float)(adc1_value/4096);//转换为电压值
			adc1_value=(int)(adc1_value*50);
			TIM_SetCompare1(TIM1,adc1_value);
			
	 }
}


void ADC1_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	ADC_InitTypeDef ADC_InitStructure;
	 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	//使能PB端口时钟
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;			    //LED0-->PB.0端口配置
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN; 	    //模拟输入
  GPIO_Init(GPIOA, &GPIO_InitStructure);			    //初始化GPIOB.0
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);	//使能ADC1时钟
	RCC_ADCCLKConfig(RCC_PCLK2_Div6); //设置ADC时钟频率
	
	ADC_DeInit(ADC1);//初始化ADC1
	ADC_InitStructure.ADC_Mode=ADC_Mode_Independent;//独立模式
	ADC_InitStructure.ADC_ScanConvMode=ENABLE;//使能扫描模式（多通道）
	ADC_InitStructure.ADC_ContinuousConvMode=ENABLE;//连续模式
	ADC_InitStructure.ADC_NbrOfChannel=1;//1个ADC通道
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;	//转换由软件触发启动
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;	//ADC数据右对齐
	ADC_Init(ADC1, &ADC_InitStructure);	//根据ADC_InitStruct中指定的参数初始化外设ADCx的寄存器   
	ADC_RegularChannelConfig(ADC1, ADC_Channel_8, 1, ADC_SampleTime_55Cycles5 );	//ADC1,ADC通道,采样时间为55.5周期	  			    
	ADC_Cmd(ADC1, ENABLE);	//使能指定的ADC1
	
	ADC_ResetCalibration(ADC1);//使能复位校准  
	while(ADC_GetResetCalibrationStatus(ADC1));//等待复位校准结束
	ADC_StartCalibration(ADC1);//开启AD校准
	while(ADC_GetCalibrationStatus(ADC1));//等待校准结束
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);//使能指定的ADC1的软件转换启动功能
}

void TIM_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_BaseStructure;
	TIM_OCInitTypeDef TimOCInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE);	//使能PA端口时钟，使能复用时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	
	 
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;			    //PA.8端口配置
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 	    //复用推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	    //IO口速度为2MHz
  GPIO_Init(GPIOA, &GPIO_InitStructure);			    //初始化GPIOA.8
	
	TIM_BaseStructure.TIM_Prescaler=359;//数值,预分频系数控制定时器的周期
	TIM_BaseStructure.TIM_Period=999;//数值，自动重装载值大小控制计数个数
	TIM_BaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_BaseStructure.TIM_CounterMode=TIM_CounterMode_Up;//向上计数模式
	TIM_TimeBaseInit(TIM1,&TIM_BaseStructure);

	TimOCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;//PWM模式1
	TimOCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;//有效电平为高
	TimOCInitStructure.TIM_Pulse=200;
	TimOCInitStructure.TIM_OutputState=TIM_OutputState_Enable;//使能输出
	TIM_OC1Init(TIM1,&TimOCInitStructure);
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);//使能重装载器
	TIM_ARRPreloadConfig(TIM1,ENABLE);
	TIM_Cmd(TIM1, ENABLE); //使能TIM3
	TIM_CtrlPWMOutputs(TIM1,ENABLE);
}
