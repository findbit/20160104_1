

#define GPJ2CON 	0XE0200280
#define GPJ2DAT 	0XE0200284
#define WTCON   	0XE2700000
#define SVC_STACK 	0XD0037D80

.global _start	//把_Start链接属性改为外部，消除链接时的警告
_start:

	//第一步：关看门狗
	ldr r0, =WTCON
	ldr r1, =0x0
	str r1, [r0]

	//第二步，设置svc栈
	ldr sp, =SVC_STACK
	
	//第三步，开/关icache
	mrc p15,0,r0,c1,c0,0  	//读出cp15的c1到r0中
	bic r0,r0, #(1 << 12) 	//bit12置0，关icache
	orr r0,r0, #(1 << 12) 	//bit12置1，开icac
 	mcr p15,0,r0,c1,c0,0
	
	
	//从这里开始就可以调用C程序了。
	//从这里开始就可以调用C程序了。
	//从这里开始就可以调用C程序了。
	
	bl led_blink
//汇编最后的这个死循环不能丢

	b .


