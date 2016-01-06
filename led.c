


#define GPJ2CON 	0XE0200280
#define GPJ2DAT 	0XE0200284

#define rGPJ2CON *((volatile unsigned int *)GPJ2CON)
#define rGPJ2DAT *((volatile unsigned int *)GPJ2DAT)

void delay(void);

void led_blink(void)
{
	//led�ĳ�ʼ����Ҳ���ǰ�GPJ0CON�е����λ����Ϊ���
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
	volatile unsigned int i = 900000;//volatile ���ñ������Ż�������������������ʱ��
	while(i--);
}
#if 0
//��һ�������������Ŷ�����Ϊ���ģʽ�����벻��
	ldr r0, =0x00001111	//�Ӻ����=���Կ����õ���ldrαָ���Ϊ
	ldr r1, =GPJ2CON
	str r0, [r1]
	
fashion:	

    //��2�����ر�����LED
	ldr r0, = 0XFF
	ldr r1, =GPJ2DAT
	str r0, [r1]
	
	//��3��������LED1(JPG2_0����͵�ƽ)
	ldr r0, = ((~(1 << 0)) & (0XFF))
	ldr r1, =GPJ2DAT
	str r0, [r1]
	
	//��4������ʱ
	bl delay
	
	//��5��������LED2(JPG2_1����͵�ƽ)
	ldr r0, = ((~(1 << 1)) & (0XFF))
	ldr r1, =GPJ2DAT
	str r0, [r1]
	
	//��6������ʱ
	bl delay
	
	//��7��������LED3(JPG2_2����͵�ƽ)
	ldr r0, = ((~(1 << 2)) & (0XFF))
	ldr r1, =GPJ2DAT
	str r0, [r1]
	
	//��8������ʱ
	bl delay
	
	//��9��������LED4(JPG2_3����͵�ƽ)
	ldr r0, = ((~(1 << 3)) & (0XFF))
	ldr r1, =GPJ2DAT
	str r0, [r1]
	
	//��10������ʱ
	bl delay
	
	//��11����ȫ������
	ldr r0, = ((0) & (0XFF))
	ldr r1, =GPJ2DAT
	str r0, [r1]
	
	//��12������ʱ
	bl delay
	
	//��13����Ϩ��LED4(JPG2_3����͵�ƽ)
	ldr r0, = (((1 << 3)) | (0X00))
	ldr r1, =GPJ2DAT
	str r0, [r1]
	
	//��14������ʱ
	bl delay
	
	//��15��������LED3(JPG2_2����͵�ƽ)
	ldr r0, = (((1 << 2)) | (0X00))
	ldr r1, =GPJ2DAT
	str r0, [r1]
	
	//��16������ʱ
	bl delay
	
	//��17����Ϩ��LED2(JPG2_1����͵�ƽ)
	ldr r0, = (((1 << 1)) | (0X00))
	ldr r1, =GPJ2DAT
	str r0, [r1]
	
	//��18������ʱ
	bl delay
	
	//��19����Ϩ��LED1(JPG2_0����͵�ƽ)
	ldr r0, = (((1 << 0)) | (0X00))
	ldr r1, =GPJ2DAT
	str r0, [r1]
	
	b fashion


delay:
	ldr r2, =9000000
	
	ldr r3, =0x0
delay_loop:
	sub r2, r2, #1	//r2 = r2 - 1 
	cmp r2, r3  	//cmp��Ӱ��Z��־λ�����r2����r3��Z= 1,��һ����eq�ͻ����
	bne delay_loop
	mov pc, lr		//�������÷���
	
#endif
