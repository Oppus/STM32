#include "stm32f10x.h"
#include "KEY.h"
#include "LED.h"

void Dfine(void)
{
  LED0_Config();
	LED_run_Config();
	KEY0();
}

