.text
.global _start

_start:

	/*关闭看门狗*/
	ldr r0, =0x53000000
	ldr r1, =0
	str r1, [r0]

	/*设置MPLL：PCLK：HCLK = 400M：100M：50M*/
	/*LOCKTIME（0x4c000000）= 0xFFFFFFFF*/
	ldr r0, = 0x4c000000
	ldr r1, = 0xFFFFFFFF
	str r1, [r0]

	/*CLKDIVN（0x4c000014）= 0x5，FCLK：HCLK：PCLK = 1:4:8*/
	ldr r0, = 0x4c000014
	ldr r1, = 0x5
	str r1, [r0]

	/*设置CPU工作于异步模式*/
	mrc p15,0,r0,c1,c0,0
	orr r0,r0,#0xc0000000	//#R1_nF:OR:R1_iA
	mcr p15,0,r0,c1,c0,0

	/*设置MPLLCON（0x4c000004）=  (92 << 12) | (1 << 4) | (1 << 0)*/
	ldr r0, = 0x4c000004
	ldr r1, =  (92 << 12) | (1 << 4) | (1 << 0)
	str r1, [r0]

	/*一旦设置PLL，就会锁定lock time直到PLL输出稳定，然后CPU工作于新的频率*/

	/*设置内存：sp栈*/
	//ldr sp, = 4096	/*Nand启动*/
	//ldr sp, = 0x40000000 /*nor启动*/

	/*自动分辨Nor/Nand启动*/
	/*写0到0地址再读出来，如果得到0表示0地址的值被修改了，即为Nand启动；否则为Nor启动*/
	mov r1, #0
	ldr r0, [r1]	//读出原值，备份
	str r1, [r1]	//往0地址写入0
	ldr r2, [r1]	//读0地址值存到r2
	cmp r1, r2	//对比写入后和写入前0地址的值
	ldr sp, =0x40000000 /*先假设为nor启动*/
	moveq sp, #4096	//如果r1==r2，则为Nand启动
	streq r0, [r1]	//恢复0地址的值

	/*调用main*/
	bl main

halt:
	bl halt
