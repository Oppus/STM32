#include "stm32f10x.h"
#include "LED.h"
#include "EXTI.h"
int a=0;

int main()
{

	LED0();
	KEYInit();
	EXTI_Config();
	NVIC_Config();
	
	while(1);
}
		
