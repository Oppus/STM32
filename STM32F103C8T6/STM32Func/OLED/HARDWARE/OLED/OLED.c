#include "OLED.h"

#include "ASCII_8x16.h" //引入字体 ASCII
#include "CHS_16x16.h" //引入汉字字体 
#include "PIC1.h" //引入图片

void OLED0561_Init(void)
{
	OLED_DISPLAY_ON();
	OLED_DISPLAY_CLEAR();
	OLED_DISPLAY_OFF();
}

void OLED_DISPLAY_ON(void)
{
	u8 buf[28]={
	0xAE, //0xAE开显示，0xAF关显示
	0x00,0x10,//开始地址
	0xD5,0x80,//显示时钟频率
	0xA8,0x3F,//复用率
	0XB0,//写入页位置（0xB0~7）
	0x40,//显示开始线
	0x8D,0x14,//VCC电源
	0xA1,//设置段重新映射
	0xC8,//COM输出方式
	0xDA,0x12,//COM输出方式
	0x81,0xFF,//对比度，指令：0x81，"0xFF"数据：0~255（255最高）
	0xD9,0xF1,//充电周期
	0xDb,0x30,//VCC电压输出
	0x20,0x00,//水平寻址设置
	0xA4,//0xa4:正常显示，0xa5:整体点亮
	0xA6,//0xa6:正常显示，0xa7:反色显示
	0xAF//0xae:关显示，0xaf:开显示
	}; //
	I2C_SAND_BUFFER(OLED0561_ADD,COM,buf,28);//OLED指令发送
}

void OLED_DISPLAY_OFF(void)
{
	u8 buf[3]=
	{
		0xae,//0xae:关显示，0xaf:开显示
		0x8d,0x10,//VCC电源
	}; //
	I2C_SAND_BUFFER(OLED0561_ADD,COM,buf,3);
}

void  OLED_DISPLAY_LIT(u8 x)//亮度调节
{
	I2C_SAND_BYTE(OLED0561_ADD,COM,0x81);
	I2C_SAND_BYTE(OLED0561_ADD,COM,x);//x亮度值(0-255)
}

void OLED_DISPLAY_CLEAR(void)
{
	u8 j,t;
	for (t=0xB0;t<0xB8;t++)
	{
		I2C_SAND_BYTE(OLED0561_ADD,COM,t);//页地址？
		I2C_SAND_BYTE(OLED0561_ADD,COM,0x10);//起始列地址高四位
		I2C_SAND_BYTE(OLED0561_ADD,COM,0x00);//起始列地址低四位
		for(j=0;j<132;j++)
		{
			I2C_SAND_BYTE(OLED0561_ADD,DAT,0x00);//写数据0000 0000
		}
	}
}

void OLED_DISPLAY_8x16(u8 x,u8 y,u16 w)//x页地址，y列坐标，w汉字编号
{
	u8 j,t,c=0;
	for(t=0;t<2;t++)
	{
		I2C_SAND_BYTE(OLED0561_ADD,COM,0xB0+x);//页地址（从0xB0到0xB7）
		I2C_SAND_BYTE(OLED0561_ADD,COM,y/16+0x10);//起始列地址高四位
		I2C_SAND_BYTE(OLED0561_ADD,COM,y%16);//起始列地址低四位
		for(j=0;j<8;j++)
		{
			I2C_SAND_BYTE(OLED0561_ADD,DAT,ASCII_8x16[(w*16)+c-512]);
			c++;
		}
		x++;
	}
}

void OLED_DISPLAY_8x16_BUFFER(u8 row,u8 *str)
{
	u8 r=0;
	while(*str != '\0')
		{
			OLED_DISPLAY_8x16(row,r*8,*str++);
			r++;
    }	
}

void OLED_DISPLAY_16x16(u8 x,u8 y,u16 w)//x页地址，y列坐标，w汉字编号
{
	u8 j,t,c=0;
	for(t=0;t<2;t++)
	{
		I2C_SAND_BYTE(OLED0561_ADD,COM,0xB0+x);//页地址（从0xB0到0xB7）
		I2C_SAND_BYTE(OLED0561_ADD,COM,y/16+0x10);//起始列地址高四位
		I2C_SAND_BYTE(OLED0561_ADD,COM,y%16);//起始列地址低四位
		for(j=0;j<8;j++)
		{
			I2C_SAND_BYTE(OLED0561_ADD,DAT,ASCII_8x16[(w*32)+c]);
			c++;
		}
		x++;
	}
		I2C_SAND_BYTE(OLED0561_ADD,COM,0xAF); //开显示 

}

void OLED_DISPLAY_PIC1(void)
{
	u8 m,i;
	for(m=0;m<8;m++)
	{
		I2C_SAND_BYTE(OLED0561_ADD,COM,0xb0+m);
		I2C_SAND_BYTE(OLED0561_ADD,COM,0x10);
		I2C_SAND_BYTE(OLED0561_ADD,COM,0x02);
		for(i=0;i<128;i++)
		{
			I2C_SAND_BYTE(OLED0561_ADD,DAT,PIC1[i+m*128]);
		}
	}
}


