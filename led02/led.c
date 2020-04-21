int main()
{
	/*两个寄存器：GPFCON控制引脚输出；pGPFDAT控制引脚输出高电平（点亮led）*/
	volatile unsigned int  *pGPFCON = (volatile unsigned int *)0x56000050;
	volatile unsigned int *pGPFDAT = (volatile unsigned int *)0x56000054;

	/*配置FPG4为输出引脚*/
	*pGPFCON = 0x100;
	
	/*配置GPF4输出0（点亮led）*/
	*pGPFDAT = 0;

	return 0;
}
