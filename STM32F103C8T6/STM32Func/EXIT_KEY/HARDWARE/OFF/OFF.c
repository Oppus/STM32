#include "OFF.h"
#include "stm32f10x.h"
#include "check.h"
#include "LED.h"
void Delay(u32 count)
{
   u32 i=0;
   for(;i<count;i++);
}

void OFF1_Config(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	    						//使能PA端口时钟
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_4|GPIO_Pin_3|GPIO_Pin_8;  //LED0-->PA.5,4,3端口配置
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	 								//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;									//IO口速度为2MHz
  GPIO_Init(GPIOA, &GPIO_InitStructure);			     							//初始化GPIOA.5,4,3
  while(1)
  {
    GPIO_SetBits(GPIOA,GPIO_Pin_5|GPIO_Pin_4|GPIO_Pin_3|GPIO_Pin_8);			//PA.5,4,3,8输出高
	if(KEY0_IsOn() ==0)
    {
      Delay(50);		
	  if(KEY0_IsOn() ==0)
	  {
		LED_run_Config();  
		break;
	  }
    }
  }

}
  
void OFF0_Config(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	//使能PA端口时钟
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;			    //LED0-->PA.8端口配置
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	    //推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;	    //IO口速度为2MHz
  GPIO_Init(GPIOA, &GPIO_InitStructure);			    //初始化GPIOA.8
	
  GPIO_SetBits(GPIOA,GPIO_Pin_8);					    //PA.8输出高
  

}
