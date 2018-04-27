#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int
uchar key,a;
sbit led1=P1^0;
sbit led2=P1^1;
sbit led3=P1^2;
sbit led4=P1^3;
sbit led5=P1^4;
sbit led6=P1^5;
sbit led7=P1^6;
sbit led8=P1^7;
//sbit key1=P2^0;
//sbit key2=P2^1;
//sbit key3=P2^2;
//sbit key4=P2^3;
void delay(uint m)
{
uchar i,j;
for(i=110;i>0;i--)
for(j=m;j>0;j--);
}

void init ()
{
	TMOD=0X20;
	TL1 = 0xFA;		//�趨��ʱ��ֵ
	TH1 = 0xFA;		//�趨��ʱ����װֵ
	TR1=1;
	REN=1;
	SM0=0;
	SM1=1;
	EA=1;
	ES=1;
	
}

void light1()    //һ���Ʒ�ʽ
{
	led1=0;
	delay(500);
	led2=0;
	delay(500);
	led3=0;
	delay(500);
	led4=0;
	delay(500);
	led5=0;
	delay(500);
	led6=0;
	delay(500);
	led7=0;
	delay(500);
	led8=0;
	delay(500);
	P1=0xff;
}
void light2()   //�����Ʒ�ʽ
{
	led8=0;
	delay(500);
	led7=0;
	delay(500);
	led6=0;
	delay(500);
	led5=0;
	delay(500);
	led4=0;
	delay(500);
	led3=0;
	delay(500);
	led2=0;
	delay(500);
	led1=0;
	delay(500);
	P1=0xff;
}
void light3()   //�����Ʒ�ʽ
{
	uchar c=0xfe;
	while(1)
	{   delay(500);
		c=_crol_(c,1);
		P1=c;
		delay(500);
	}
}
void light4()   //�����Ʒ�ʽ
{
	uchar c=0x7f;
	while(1)
	{   delay(500);
		c=_cror_(c,1);
		P1=c;
		delay(500);
	}
}
void main()        //������
{
	init();
	while(1)
	{
		if(key=='1')  //�԰���һ���
		{  
				light1();
		}
	
		if(key=='2')   //�԰��������
		{  
				light2();
	 	}
	
		if(key=='3')   //�԰��������
		{
				light3();
		}
		if(key=='4')   //�԰����ļ��
		{ 
				light4();
		}
	
	}
}

void ser()interrupt 4
{
	RI=0;
	a=SBUF;
	key=a;
}
