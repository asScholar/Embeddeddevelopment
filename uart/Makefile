all:
	arm-linux-gcc -c -o led.o led.c
	arm-linux-gcc -c -o start.o start.S
	arm-linux-gcc -c -o uart.o uart.c
	arm-linux-gcc -c -o test.o test.c
	arm-linux-ld -Ttext 0 start.o led.o uart.o test.o -o test.elf
	arm-linux-objcopy -O binary -S test.elf test.bin
	arm-linux-objdump -D test.elf > test.dis
clean:
	rm *.bin *.o *.elf *.dis
