#include "stm32f10x.h"
#include "TIM.h"
#include "LED.h"




int main(void)
{
	NVIC_Config();
	TIM_Init();
	LED0_Config();
	while(1);
	
  //NVIC_Config();
  
}
	
