#include "stm32f10x.h"
#include "pwm.h"
#include "delay.h"
#include "sys.h"
#include "oled.h"
#include "timer.h"
#include "math.h"

extern u8  ss;		    				
extern u16 fq;

void TIM2_Delay500MS(void);
void RCC_Configuration(void);
int main(void)
{
	 u16 z;
	 u8 i;
 	 u16 buffer[7];	
	 TIM2_Delay500MS();
	 RCC_Configuration();
   I2C_Config();
   OLED_Init();
	 OLED_DISPLAY_LIT(100);
	 OLED_DISPLAY_8x16_BUFFER(0,"   DC Motor  ");
	 OLED_DISPLAY_8x16_BUFFER(2,"    speed:   ");
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	
   TIM3_Cap_Init(0XFFFF,72-1);	
	 
	
	
	while(1)
	{  

    
	  
		
		
	 while(ss==0x80)
		{
			ss=0x00;
		  z=60000000/(20*fq);
			/////////////////////////////////////OLEDœ‘ æÀŸ∂»
        for(i=0;i<7;i++)
				{
					buffer[i]=z/((int)pow(10,6-i));
					z=z-buffer[i]*((int)pow(10,6-i));
				}
				for(i=0;i<7;i++)
				{
					OLED_DISPLAY_8x16(4,(i+4)*8,buffer[i]+0x30);
				}
				
				//OLED_DISPLAY_8x16_BUFFER(0,"   DC Motor  ");
	      //OLED_DISPLAY_8x16_BUFFER(2,"    speed:   ");
				//OLED_Init();
	      //OLED_DISPLAY_LIT(100);
				
				TIM2_Delay500MS();
			//////////////////////////////////
				
		}
		
		
	}
	
}
	

