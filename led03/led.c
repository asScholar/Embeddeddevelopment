delay(volatile int d)
{
	while(d--);
}

int led_on(int which)
{
	unsigned int  *pGPFCON = (unsigned int *)0x56000050;
	unsigned int *pGPFDAT = (unsigned int *)0x56000054;
	
	if (which == 4){
		/*配置FPG4为输出引脚*/
		*pGPFCON = 0x100;
	}else if (which == 5){
		/*配置FPG5为输出引脚*/
		*pGPFCON = 0x400;
	}

	/*配置GPF4/5输出0（点亮led）*/
	pGPFDAT = 0;
}
