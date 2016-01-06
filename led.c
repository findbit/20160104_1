


#define GPJ2CON 	0XE0200280
#define GPJ2DAT 	0XE0200284

#define rGPJ2CON *((volatile unsigned int *)GPJ2CON)
#define rGPJ2DAT *((volatile unsigned int *)GPJ2DAT)

void delay(void);

void led_blink(void)
{
	//led的初始化，也就是把GPJ0CON中的相关位设置为输出
	 //volatile unsigned int *p = (unsigned int *)GPJ2CON;
	 //*p = 0x00001111;
	 //volatile 	unsigned int *p1 = (unsigned int *)GPJ2DAT;
	 rGPJ2CON = 0x00001111;
	 
	while(1)
	{
		rGPJ2DAT = ((0 << 3) & (0 << 2) & (0 << 1) & (0 << 0));
		delay();
		rGPJ2DAT = ((1 << 3) | (1 << 2) | (1 << 1) | (1 << 0));
		delay();
	}
	
}

void delay(void)
{
	volatile unsigned int i = 900000;//volatile 不让编译器优化，这样才能真正消耗时间
	while(i--);
}
#if 0
//第一步：把所有引脚都设置为输出模式，代码不变
	ldr r0, =0x00001111	//从后面的=可以看出用的是ldr伪指令，因为
	ldr r1, =GPJ2CON
	str r0, [r1]
	
fashion:	

    //第2步：关闭所有LED
	ldr r0, = 0XFF
	ldr r1, =GPJ2DAT
	str r0, [r1]
	
	//第3步：点亮LED1(JPG2_0输出低电平)
	ldr r0, = ((~(1 << 0)) & (0XFF))
	ldr r1, =GPJ2DAT
	str r0, [r1]
	
	//第4步：延时
	bl delay
	
	//第5步：点亮LED2(JPG2_1输出低电平)
	ldr r0, = ((~(1 << 1)) & (0XFF))
	ldr r1, =GPJ2DAT
	str r0, [r1]
	
	//第6步：延时
	bl delay
	
	//第7步：点亮LED3(JPG2_2输出低电平)
	ldr r0, = ((~(1 << 2)) & (0XFF))
	ldr r1, =GPJ2DAT
	str r0, [r1]
	
	//第8步：延时
	bl delay
	
	//第9步：点亮LED4(JPG2_3输出低电平)
	ldr r0, = ((~(1 << 3)) & (0XFF))
	ldr r1, =GPJ2DAT
	str r0, [r1]
	
	//第10步：延时
	bl delay
	
	//第11步：全部点亮
	ldr r0, = ((0) & (0XFF))
	ldr r1, =GPJ2DAT
	str r0, [r1]
	
	//第12步：延时
	bl delay
	
	//第13步：熄灭LED4(JPG2_3输出低电平)
	ldr r0, = (((1 << 3)) | (0X00))
	ldr r1, =GPJ2DAT
	str r0, [r1]
	
	//第14步：延时
	bl delay
	
	//第15步：点亮LED3(JPG2_2输出低电平)
	ldr r0, = (((1 << 2)) | (0X00))
	ldr r1, =GPJ2DAT
	str r0, [r1]
	
	//第16步：延时
	bl delay
	
	//第17步：熄灭LED2(JPG2_1输出低电平)
	ldr r0, = (((1 << 1)) | (0X00))
	ldr r1, =GPJ2DAT
	str r0, [r1]
	
	//第18步：延时
	bl delay
	
	//第19步：熄灭LED1(JPG2_0输出低电平)
	ldr r0, = (((1 << 0)) | (0X00))
	ldr r1, =GPJ2DAT
	str r0, [r1]
	
	b fashion


delay:
	ldr r2, =9000000
	
	ldr r3, =0x0
delay_loop:
	sub r2, r2, #1	//r2 = r2 - 1 
	cmp r2, r3  	//cmp会影响Z标志位，如果r2等于r3则Z= 1,下一句中eq就会成立
	bne delay_loop
	mov pc, lr		//函数调用返回
	
#endif
