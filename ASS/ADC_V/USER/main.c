#include "stm32f10x.h"


void TIMInit(void);
void NVIC_Config(void);
void TIM2_Config(void);
void ADC1_Config(void);
volatile unsigned char adc1_flag;
volatile unsigned short adc1_value=0xAAA;
volatile float voltage_PB0=1.0;

int main(void)
{
	NVIC_Config();
	TIMInit();
	TIM2_Config();
	ADC1_Config();
	adc1_flag=0;//ADC1标志位置0
	
	while(1)
	{
		if(adc1_flag)
		{
			adc1_value=ADC_GetConversionValue(ADC1);//返回最近一次ADC1规则通道转换结果
			voltage_PB0=(int) adc1_value /4096*1000;
			TIM_SetCompare2(TIM3,voltage_PB0);

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
		
	TIM_BaseStructure.TIM_Prescaler=36000-1;//数值,预分频系数控制定时器的周期
	TIM_BaseStructure.TIM_Period=1000-1;//数值，自动重装载值大小控制计数个数
	TIM_BaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_BaseStructure.TIM_CounterMode=TIM_CounterMode_Up;//向上计数模式
	TIM_TimeBaseInit(TIM2,&TIM_BaseStructure);
	TIM_ClearFlag(TIM2,TIM_FLAG_Update);
	
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE ); //使能指定的TIM3中断,允许更新中断
	
	TIM_Cmd(TIM2,ENABLE);
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

void TIMInit(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_BaseStructure;
	TIM_OCInitTypeDef TimOCInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO, ENABLE);	//使能PB端口时钟，使能复用时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE); //Timer3部分重映射  TIM3_CH2->PB5    

	 
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;			    //PB.5端口配置
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 	    //复用推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	    //IO口速度为50MHz
  GPIO_Init(GPIOB, &GPIO_InitStructure);			    //初始化GPIOB.5
	
	TIM_BaseStructure.TIM_Prescaler=359;//数值,预分频系数控制定时器的周期
	TIM_BaseStructure.TIM_Period=999;//数值，自动重装载值大小控制计数个数
	TIM_BaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_BaseStructure.TIM_CounterMode=TIM_CounterMode_Up;//向上计数模式
	TIM_TimeBaseInit(TIM3,&TIM_BaseStructure);

	TimOCInitStructure.TIM_OCMode=TIM_OCMode_PWM2;//PWM模式2
	TimOCInitStructure.TIM_OCPolarity=TIM_OCPolarity_Low;//有效电平为高
	TimOCInitStructure.TIM_Pulse=200;
	TimOCInitStructure.TIM_OutputState=TIM_OutputState_Enable;//使能输出
	TIM_OC2Init(TIM3,&TimOCInitStructure);
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);//使能重装载器
	TIM_ARRPreloadConfig(TIM3,ENABLE);
	TIM_Cmd(TIM3, ENABLE);
	TIM_CtrlPWMOutputs(TIM3,ENABLE);
}
