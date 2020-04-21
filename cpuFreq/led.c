#include "s3c2440_soc.h"

/*已在s3c2440_soc.h文件中定义了宏*/
//#define GPFCON (*((volatile unsigned int *)0x56000050))
//#define GPFDAT  (*((volatile unsigned int *)0x56000054))

void delay(volatile int d)
{
	while(d--);
}

int main()
{

	int val = 0; /* val: 0b000, 0b111 */
	int tmp;

	/*配置GPFCON让GPF4/5/6为输出引脚，先清位再置位*/
	GPFCON &= ~((3 << 8) | (3 << 10) | (3 << 12));
	GPFCON |= ((1 << 8) | (1 << 10) | (1 << 12));

	/*循环点亮led，先清位再置位*/
	while (1){

		tmp = ~val;
		tmp &= 7;

		GPFDAT &= ~(7 << 4);
		GPFDAT |= (tmp << 4);
	
		delay(100000);

		val++;
		if (val == 8)
			val = 0;
	}

	return 0;
}
