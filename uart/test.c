#include "s3c2440_soc.h"
#include "uart.h"

int main()
{

	unsigned char c;

	uart0_init();
	puts("Hello Baiwen!\n");

	while (1){
	
		c = getchar();
		putchar(c);
	}

	return 0;
}
