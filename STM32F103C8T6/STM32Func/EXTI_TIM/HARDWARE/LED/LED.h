#ifndef __LED_H
#define __LED_H
#include "sys.h"

#define LED PAout(8)

void LED0_Config(void);
void LED_On(void);
void LED_Off(void);

#endif
