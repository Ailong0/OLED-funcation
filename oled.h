#ifndef __oled_H__
#define __oled_H__

#include "reg52.h"
#define  u8   unsigned short int 
#define  u32  unsigned int	
	// ------------------------------------------------------------
// IO口模拟I2C通信
// SCL接P1^3
// SDA接P1^2
// ------------------------------------------------------------
sbit SCL=P1^6; //串行时钟
sbit SDA=P1^7; //串行数据

#define high 1
#define low 0

#define	Brightness	0xCF 
#define X_WIDTH 	128
#define Y_WIDTH 	64


void delay(unsigned int z);
void IIC_Start();
void IIC_Stop();
void Write_IIC_Byte(unsigned char IIC_Byte); 
void OLED_WrDat(unsigned char IIC_Data);
void OLED_WrCmd(unsigned char IIC_Command);
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_Fill(unsigned char bmp_dat); 
//void OLED_CLS(void);
u32 oled_pow(u8 m,u8 n);
void OLED_Init(void);
void OLED_ShowChar(u8 x,u8 y,u8 chr);
void OLED_P6x8Str(unsigned char x, y,unsigned char ch[]);
void OLED_P8x16Str(unsigned char x, y,unsigned char ch[]);
void OLED_P16x16Ch(unsigned char x, y, N);
//void Draw_BMP(unsigned char x0, y0,x1, y1,unsigned char BMP[]);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len);
	
#endif