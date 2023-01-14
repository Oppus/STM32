#include "stm32f10x.h"
#include "timer.h"
#include "pwm.h"
#include "oled.h"
void TIM3_Cap_Init(u16 arr,u16 psc)
{     
   GPIO_InitTypeDef GPIO_InitStructure;
   TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
   NVIC_InitTypeDef NVIC_InitStructure;
	 TIM_ICInitTypeDef  TIM3_ICInitStructure;
	

   RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);  
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	////
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO , ENABLE);
  GPIO_AFIODeInit();
	
	
	
	
	
	/////
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_7;  
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;   
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_ResetBits(GPIOA,GPIO_Pin_7);                     
    
    TIM_TimeBaseStructure.TIM_Period = arr; 
    TIM_TimeBaseStructure.TIM_Prescaler =psc;      
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; 
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); 
  
 
    TIM3_ICInitStructure.TIM_Channel = TIM_Channel_2; 
    TIM3_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;    
    TIM3_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; 
    TIM3_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;     
    TIM3_ICInitStructure.TIM_ICFilter = 0x00;
    TIM_ICInit(TIM3, &TIM3_ICInitStructure);
			

    NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn;   
	  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;  
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
    NVIC_Init(&NVIC_InitStructure);  
    
    TIM_ITConfig(TIM3,TIM_IT_Update|TIM_IT_CC2,ENABLE);
    TIM_Cmd(TIM3,ENABLE ); 
		
}
/////////////////////////////////////////////////////////
void TIM3_Cap_ExInit(u16 arr,u16 psc)
{     
   GPIO_InitTypeDef GPIO_InitStructure;
   TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
   NVIC_InitTypeDef NVIC_InitStructure;
	 TIM_ICInitTypeDef  TIM3_ICInitStructure;
	

   RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, DISABLE);  
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, DISABLE);
	
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO , DISABLE);
    GPIO_AFIODeInit();
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_7;  
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;   
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_ResetBits(GPIOA,GPIO_Pin_7);                     
    
    TIM_TimeBaseStructure.TIM_Period = arr; 
    TIM_TimeBaseStructure.TIM_Prescaler =psc;      
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; 
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); 
  
 
    TIM3_ICInitStructure.TIM_Channel = TIM_Channel_2; 
    TIM3_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;    
    TIM3_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; 
    TIM3_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;     
    TIM3_ICInitStructure.TIM_ICFilter = 0x00;
    TIM_ICInit(TIM3, &TIM3_ICInitStructure);
			

    NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn;   
	  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;  
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  
    NVIC_InitStructure.NVIC_IRQChannelCmd = DISABLE; 
    NVIC_Init(&NVIC_InitStructure);  
    
    TIM_ITConfig(TIM3,TIM_IT_Update|TIM_IT_CC2,DISABLE);
    TIM_Cmd(TIM3,DISABLE );                             




}

//////////////////////////////////////////////////////////////////
u16 fq;
 
 u8 ss; 
void TIM3_IRQHandler(void)
{ 
   static int turn=0;
   u32    TIM3CH2_CAPTURE_VAL2;
	   PWMQJ();
     if((TIM_GetITStatus(TIM3, TIM_IT_CC2) != RESET)) 
    {  			
       if(turn==0) 
			 {
         TIM_SetCounter(TIM3,0);
				 turn=1;
			 } 
			else if(turn==1)
			 {
				 TIM3CH2_CAPTURE_VAL2=TIM_GetCapture2(TIM3);
				 turn=0;
				 fq=TIM3CH2_CAPTURE_VAL2;
			   ss=0x80;                            
       }  
			 TIM_ClearITPendingBit(TIM3, TIM_IT_CC2|TIM_IT_Update);
		}		 
}
