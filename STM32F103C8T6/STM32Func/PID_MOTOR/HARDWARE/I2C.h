#ifndef __i2c_H
#define __i2c_H
#include "sys.h"

#define I2C_SCL   GPIO_Pin_6
#define I2C_SDA   GPIO_Pin_7

#define HostAddress  0xc0
#define BusSpeed     200000
void I2C_GPIO_Init(void);
void I2C_Config(void);
void I2C_SAND_BUFFER(u8 SlaveAddr, u8 WriteAddr,u8*pBuffer,u16 NumByteToWrite);
void I2C_SAND_BYTE(u8 SlaveAddr,u8 writeAddr,u8 pBuffer);
void I2C_READ_BUFFER(u8 SlaveAddr,u8 readAddr,u8* pBuffer,u16 NumByteToRead);
u8 I2C_READ_BYTE(u8 SlaveAddr,u8 readAddr);

#endif
