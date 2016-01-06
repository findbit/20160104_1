led.bin: Start.o led.o
	arm-linux-ld -Ttext 0x0 -o led.elf $^
	arm-linux-objcopy -O binary led.elf led.bin
	arm-linux-objdump -D led.elf > led_elf.dis
	gcc mkv210_image.c -o mkmini210
	./mkmini210 led.bin 210.bin
	
%.o : %.S
	arm-none-linux-gnueabi-gcc -o $@ $< -c -nostdlib
	
%.o : %.c
	arm-none-linux-gnueabi-gcc -o $@ $< -c -nostdlib
	
clean:
	rm *.o *.elf *.bin *.dis mkmini210 -f
	