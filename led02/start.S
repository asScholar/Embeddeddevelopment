.text
.global _start

_start:

	/*设置内存：sp栈*/
	ldr sp, = 4096	/*Nand启动*/
	//ldr sp, = 0x40000000 /*nor启动*/

	/*调用main*/
	bl main

/*死循环*/
halt:
	bl halt
