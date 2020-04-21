#include "s3c2440_soc.h"

void uart0_init()
{

	/*设置引脚用于串口*/
	/*GPH2,3用于TxD0, RxD0*/
	GPHCON &= ~((3 << 4) | (3 << 6));	
	GPHCON |= ((2 << 4) | (2 << 6));

	GPHUP &= ~((1 << 2) | (1 << 3)); //使能内部上拉

	/*设置波特率115200*/
	UCON0 = 0x00000005; //PCLK，中断/查询模式
	UBRDIV0 = 26;	

	/*设置数据格式*/
	ULCON0 = 0x00000003; //8n1:8个数据位，无校验位，1个停止位	

	/*其它设置*/
}

int putchar(int c)
{

	while (!(UTRSTAT0 & (1 << 2)));
	UTXH0 = (unsigned char)c;	

	return 0;
}

int getchar(void)
{

	/*read URXH0*/
	while (!(UTRSTAT0 & (1 << 0)));
	return URXH0;	
}

int puts (const char *s)
{

	while (*s){
		
		putchar(*s);
		s++;
	}
}
