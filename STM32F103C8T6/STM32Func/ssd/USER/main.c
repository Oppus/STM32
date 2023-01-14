#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
int main()
{
  delay_init();
  led_Init();


  led_Shan();
	
}
		
