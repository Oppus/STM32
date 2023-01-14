#include "stm32f10x.h"
typedef enum {FAILED=0, PASSED= !FAILED} TestStatus;
#define BufferSize 12
uint32_t CurrDataCounterBegin=0;
volatile uint32_t CurrDataCounterrEnd=1;
TestStatus TransferStatus=FAILED;
const uint32_t SRC_Const_Buffer[BufferSize]=
{
	0x01020304,0x05060708,0x090a0b0c,0x0d0e0f10,
	0x11121314,0x15161718,0x191a1b1c,0x1d1e1f20,
	0x21222324,0x25262728,0x292a2b2c,0x2d2e2f30
};
uint32_t DST_Buffer[BufferSize];
void NVIC_Config(void);
void DMA_Config(void);
TestStatus Buffercmp(const uint32_t* pBuffer,uint32_t* pBuffer1,uint16_t BufferLength);


int main(void)
{
	NVIC_Config
}
	
