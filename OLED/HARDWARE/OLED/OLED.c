#include "OLED.h"

#include "ASCII_8x16.h" //�������� ASCII
#include "CHS_16x16.h" //���뺺������ 
#include "PIC1.h" //����ͼƬ

void OLED0561_Init(void)
{
	OLED_DISPLAY_ON();
	OLED_DISPLAY_CLEAR();
	OLED_DISPLAY_OFF();
}

void OLED_DISPLAY_ON(void)
{
	u8 buf[28]={
	0xAE, //0xAE����ʾ��0xAF����ʾ
	0x00,0x10,//��ʼ��ַ
	0xD5,0x80,//��ʾʱ��Ƶ��
	0xA8,0x3F,//������
	0XB0,//д��ҳλ�ã�0xB0~7��
	0x40,//��ʾ��ʼ��
	0x8D,0x14,//VCC��Դ
	0xA1,//���ö�����ӳ��
	0xC8,//COM�����ʽ
	0xDA,0x12,//COM�����ʽ
	0x81,0xFF,//�Աȶȣ�ָ�0x81��"0xFF"���ݣ�0~255��255��ߣ�
	0xD9,0xF1,//�������
	0xDb,0x30,//VCC��ѹ���
	0x20,0x00,//ˮƽѰַ����
	0xA4,//0xa4:������ʾ��0xa5:�������
	0xA6,//0xa6:������ʾ��0xa7:��ɫ��ʾ
	0xAF//0xae:����ʾ��0xaf:����ʾ
	}; //
	I2C_SAND_BUFFER(OLED0561_ADD,COM,buf,28);//OLEDָ���
}

void OLED_DISPLAY_OFF(void)
{
	u8 buf[3]=
	{
		0xae,//0xae:����ʾ��0xaf:����ʾ
		0x8d,0x10,//VCC��Դ
	}; //
	I2C_SAND_BUFFER(OLED0561_ADD,COM,buf,3);
}

void  OLED_DISPLAY_LIT(u8 x)//���ȵ���
{
	I2C_SAND_BYTE(OLED0561_ADD,COM,0x81);
	I2C_SAND_BYTE(OLED0561_ADD,COM,x);//x����ֵ(0-255)
}

void OLED_DISPLAY_CLEAR(void)
{
	u8 j,t;
	for (t=0xB0;t<0xB8;t++)
	{
		I2C_SAND_BYTE(OLED0561_ADD,COM,t);//ҳ��ַ��
		I2C_SAND_BYTE(OLED0561_ADD,COM,0x10);//��ʼ�е�ַ����λ
		I2C_SAND_BYTE(OLED0561_ADD,COM,0x00);//��ʼ�е�ַ����λ
		for(j=0;j<132;j++)
		{
			I2C_SAND_BYTE(OLED0561_ADD,DAT,0x00);//д����0000 0000
		}
	}
}

void OLED_DISPLAY_8x16(u8 x,u8 y,u16 w)//xҳ��ַ��y�����꣬w���ֱ��
{
	u8 j,t,c=0;
	for(t=0;t<2;t++)
	{
		I2C_SAND_BYTE(OLED0561_ADD,COM,0xB0+x);//ҳ��ַ����0xB0��0xB7��
		I2C_SAND_BYTE(OLED0561_ADD,COM,y/16+0x10);//��ʼ�е�ַ����λ
		I2C_SAND_BYTE(OLED0561_ADD,COM,y%16);//��ʼ�е�ַ����λ
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

void OLED_DISPLAY_16x16(u8 x,u8 y,u16 w)//xҳ��ַ��y�����꣬w���ֱ��
{
	u8 j,t,c=0;
	for(t=0;t<2;t++)
	{
		I2C_SAND_BYTE(OLED0561_ADD,COM,0xB0+x);//ҳ��ַ����0xB0��0xB7��
		I2C_SAND_BYTE(OLED0561_ADD,COM,y/16+0x10);//��ʼ�е�ַ����λ
		I2C_SAND_BYTE(OLED0561_ADD,COM,y%16);//��ʼ�е�ַ����λ
		for(j=0;j<8;j++)
		{
			I2C_SAND_BYTE(OLED0561_ADD,DAT,ASCII_8x16[(w*32)+c]);
			c++;
		}
		x++;
	}
		I2C_SAND_BYTE(OLED0561_ADD,COM,0xAF); //����ʾ 

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


