/////////////////////////////////////////////////////////////////////////
// Bitmap点阵数据表                                                    //
// 图片: E:\..萌∧246.bmp,纵向取模下高位,数据排列:从左到右从上到下   //
// 图片尺寸: 128 * 64                                                  //
/////////////////////////////////////////////////////////////////////////
unsigned char PIC1[] =                  // 数据表
{
			/*0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0x7F,0x3F,0xFF,0x7F,0x7F,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x9F,
      0xCF,0xF7,0xF9,0xFC,0xFF,0xFE,0xFE,0xFD,
      0xFD,0xFD,0xFB,0xFB,0xFF,0xF7,0xF7,0xEF,
      0xEF,0xFF,0xDF,0xDF,0xBF,0xBF,0xFF,0x7F,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0x7F,0x7F,0x7F,0x3F,
      0x3F,0x9F,0x9F,0x9F,0xCF,0xCF,0xCF,0xCF,
      0xE7,0xE7,0xE7,0xE7,0xE7,0xF7,0xF3,0xF3,
      0xF3,0xF3,0xF3,0xF3,0xF2,0xF3,0xF1,0xF3,
      0xF2,0xF2,0xE5,0xE5,0xED,0xEC,0xDE,0xDF,
      0xDD,0xBF,0xB7,0x77,0x7F,0xFF,0xFF,0xEF,
      0xDF,0xCF,0xFF,0xBF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0x7F,0xFF,0x3F,0xDF,0xE7,0xF9,0xFC,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0x7F,0x3F,0x3F,0x1F,0x1F,0x0F,0x0F,
      0x0F,0x0F,0x07,0x07,0x07,0x07,0x07,0x07,
      0x07,0x0F,0x0F,0x1F,0x1F,0x0F,0x47,0xE3,
      0xF3,0xF1,0xF9,0xFC,0xFC,0xFE,0xFE,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFE,0xFE,
      0xFD,0xFD,0xFB,0xFB,0xFB,0xF7,0xF7,0xEF,
      0xCE,0xCD,0x98,0x1B,0x17,0x37,0xAF,0xAF,
      0x6F,0x5F,0xBF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0x7F,0x3F,0x0F,0x07,0x03,0x01,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x8F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFB,0xF3,0xF3,0xF3,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xF3,0xF1,0xF1,
      0xF3,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFE,0xF8,0xF0,0xE1,
      0x87,0x0F,0x1F,0x7F,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0x03,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,
      0xC0,0xC0,0xC0,0xE0,0xE0,0xF0,0xF8,0xFC,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,
      0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
      0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xF8,0xE0,0x01,0x0F,0x7F,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x3F,
      0x0F,0x84,0xE0,0xF0,0xF8,0xFC,0xFE,0xFE,
      0xFE,0xFE,0xF8,0xE0,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x07,0x3F,0x7F,0xFF,
      0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0x7F,0x7F,0x3F,0x3F,0x1F,0x1F,0x1F,0x1F,
      0x1F,0x1F,0x3F,0x3F,0x7F,0xFF,0xFF,0xFF,
      0xFF,0xE3,0xC1,0xDD,0x9C,0xBE,0xBE,0xBE,
      0xBF,0xBF,0xBF,0xBF,0x3F,0x3F,0x3F,0x3F,
      0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0xBE,0xBE,
      0xBE,0xBE,0xBE,0xBC,0x9D,0xDD,0xD9,0xC3,
      0xE3,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFC,0x00,0x00,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xC7,0x80,0xF0,
      0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFE,0xF8,0xE0,0xC0,
      0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,
      0x00,0x01,0x01,0x01,0x01,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x80,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xBF,0x81,0x80,0xF8,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF*/
			0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x08,0x02,0x02,0x08,0x00,
      0x00,0x30,0x30,0x30,0xA0,0xB8,0x98,0x18,
      0x58,0x58,0x40,0x08,0x10,0x00,0x20,0x30,
      0x18,0x08,0x00,0x20,0x20,0x00,0x00,0x00,
      0x00,0x00,0x00,0x04,0x80,0x30,0xB0,0xB0,
      0x60,0x60,0x40,0xC0,0x80,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x40,0xC0,0xF4,0xC4,0xC6,0xC6,0x84,0xC4,
      0xE4,0xC8,0xF8,0xFC,0x06,0x00,0x00,0xC0,
      0xC0,0x80,0x80,0xC8,0xC8,0xC8,0x58,0xC6,
      0x58,0x81,0xC1,0xC0,0x60,0x60,0x00,0x00,
      0x00,0x00,0x00,0x02,0x60,0x02,0xFF,0xF8,
      0x00,0x00,0x00,0x00,0x00,0xC0,0xC1,0xC1,
      0xC1,0x01,0x00,0x00,0x0F,0x7E,0xE0,0x00,
      0x01,0x01,0x01,0x02,0x02,0x08,0x40,0x14,
      0x14,0x6C,0xB8,0x78,0xF0,0xC0,0xC0,0xC0,
      0xC0,0xC0,0xC0,0x40,0x40,0x40,0x40,0xC0,
      0xC0,0xC0,0xC0,0x40,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x80,0x01,0x73,0x3F,
      0x7F,0xBF,0xFF,0xBF,0x2F,0x2F,0xAF,0xFF,
      0xFD,0x65,0x64,0x3D,0x6C,0x6C,0x24,0x25,
      0x2C,0x64,0x6C,0x6C,0x26,0x36,0x80,0x80,
      0x80,0x80,0x80,0x80,0x80,0x86,0xE0,0x8F,
      0xFE,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x1E,
      0xE0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC2,
      0xF0,0xC0,0x83,0x8F,0xDF,0xFF,0xFE,0x7A,
      0x7E,0x7E,0x7E,0x6A,0x6A,0x4A,0x4A,0x4A,
      0x5A,0x5A,0x4A,0x6A,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x02,0x04,0x06,0x3C,0x6C,0x7C,0x78,
      0x5E,0x5D,0x6F,0x6F,0x7F,0x3E,0x1E,0x7F,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0x7E,0x7E,0x7E,0x7E,0x7F,0x7F,0x3F,
      0x3F,0x7F,0xFF,0xFF,0x3F,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xE0,0x80,0x80,0x80,0x80,0x80,
      0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,
      0xC0,0xC7,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
      0x0F,0x0F,0x03,0x07,0x03,0x07,0x03,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x30,0xFC,0x7C,0xFC,0xFC,0x8E,
      0x8E,0x8C,0x98,0xF8,0xF8,0xFC,0xFC,0xDC,
      0xFA,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,
      0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFB,0x19,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,
      0x40,0x80,0x80,0xBB,0xFB,0xFF,0xFF,0x3F,
      0x77,0x1F,0x02,0x00,0x01,0x01,0x00,0x00,
      0x01,0x01,0x03,0x03,0x07,0x07,0x07,0x07,
      0x07,0x03,0x03,0x03,0x03,0x01,0x01,0x3E,
      0xFF,0xFF,0x7F,0x3F,0x3F,0x3F,0x57,0xFF,
      0x82,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x9E,0x1E,0x0F,0x0D,0x07,0x07,0x1F,0x20,
      0xA0,0x20,0x00,0x70,0xE0,0xE0,0x80,0xF0,
      0xE0,0xE0,0xE0,0xE0,0xF0,0xF0,0xF0,0xF0,
      0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,
      0xD0,0xA9,0xF3,0xE7,0xFC,0xD8,0xF8,0xB8,
      0xFD,0x0D,0x0C,0x40,0x20,0x70,0x60,0xC0,
      0x60,0x40,0x40,0xC0,0xC0,0x80,0x80,0x80,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,
      0x38,0xF8,0xFC,0xFC,0xF8,0xF8,0xFC,0xFF,
      0xFE,0xFF,0xDF,0xFC,0xF8,0xEC,0x14,0x3E,
      0x0E,0x06,0x06,0x65,0x0F,0x3F,0x7F,0xFF,
      0xFF,0x7F,0x7F,0x7F,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,
      0xFE,0xFA,0xF4,0xF0,0xFE,0xFC,0xFE,0xFF,
      0xF9,0xFB,0xFB,0xFE,0xBE,0x7F,0xFF,0x7F,
      0x7F,0x7E,0x0C,0x0C,0x04,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
