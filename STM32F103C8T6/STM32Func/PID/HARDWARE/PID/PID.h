#ifndef __PID_H
#define __PID_H
#include "stm32f10x.h"


typedef struct
{
	int SetSpeed;
	float Kp;
	float Ki;
	float Kd;
	int SumSpeed;
	int last_err;
	int last_before_err;
}PIDTypeDef;
void PID_TIM(u16 arr,u16 psc);
void NVIC_Config(void);
void PIDInit(u16 speed);
int PID_Mea(PIDTypeDef *PIDx,int GetSpeed);


#endif