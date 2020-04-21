/*
 * 点亮LED：GPF4
 */
.text
.global _start

/*配置FPF4为输出引脚*/
/*把0x100写入0x56000050*/
ldr r1, = 0x56000050
ldr r0, =0x100 /*mov r0, #0x100*/
str r0, [r1]

/*配置FPF4为输出高电平*/
/*把0x10写入0x56000054*/
ldr r1, = 0x56000054
ldr r0, =0 /*mov r0, #0*/
str r0, [r1]

/*死循环*/
halt:
 	b halt
