#include<pic.h>
#define RS RB4
#define RW RB5
#define E RB6
#define s1 RB0
#define s2 RB1
#define s3 RB2
#define s4 RB3
#define C1 RC0
#define C2 RC1
#define C3 RC2
#define R1 RC3
#define R2 RC4
#define R3 RC5
#define R4 RC6
unsigned int m=0,i=0,j,v,l,z,w,y,g,p,cnts=60,k,n,q;
unsigned int a,b;
void delay(unsigned int x)
{
while(x--);
}
void lcd_cmd(a)
{
PORTD=a;
RS=0;
RW=0;
E=1;
delay(100);
E=0;
} 
void lcd_init()
{
lcd_cmd(0x38);
lcd_cmd(0x0C);
lcd_cmd(0x01);
lcd_cmd(0x06);
}
void lcd_data(b)
{
PORTD=b;
RS=1;
RW=0;
E=1;
delay(1000);
E=0;
}
void lcd_display(const unsigned char *da)
{
for(j=0;da[j]!=0;j++)
{
lcd_data(da[j]);
}
}           

void keypad()
{
while(m<10) //10digit mobile number
{
C1=1;C2=0;C3=0;delay(1000);
if(C1==1)
{
if(R1==1)                 
{
lcd_data('1');m++;
while(R1==1);
}
delay(100);
if(R2==1)
{
lcd_data('4');m++;
while(R2==1);
}
if(R3==1)
{
delay(100);
lcd_data('7');m++;
while(R3==1);
}
delay(1000);
if(R4==1)
{
delay(100);
lcd_data('*');m++;
while(R4==1);
}
}
delay(1000);
C1=0;C2=1;C3=0;delay(100);
if(C2==1)
{
if(R1==1)
{
delay(100);
lcd_data('2');m++;
while(R1==1);
}
delay(1000);
if(R2==1)
{
delay(100);
lcd_data('5');m++;
while(R2==1);
}
delay(100);
if(R3==1)
 {
delay(100);
lcd_data('8');m++;
while(R3==1);
}
delay(100);
if(R4==1)
{
delay(100);
lcd_data('0');m++;
while(R4==1);
}
delay(100);
}
C1=0;C2=0;C3=1;delay(1000);
if(C3==1)
{
if(R1==1)
{
delay(100);
lcd_data('3');m++;
while (R1==1);
}
delay(100);
if(R2==1)
{
delay(100);
lcd_data('6');m++;
while(R2==1);
}
delay(100);
if(R3==1)
{
delay(100);
lcd_data('9');m++;
while(R3==1);
}
delay(100);
if(R4==1)
{
delay(100);
lcd_data('#');m++;
while(R4==1);
}delay(10000);
}
}
}
void main()
{
TRISB=0X0F;
PORTB=0X00;
TRISC=0X78;
PORTC=0X00;
TRISD=0X00;
PORTD=0X00;
TRISE=0X00;
PORTE=0X00;
lcd_init();
while(1)
{
if((s1==1)
{
lcd_cmd(0X80);
lcd_display("Enter coin");
delay(1000);
}
if((s2==1)
{
lcd_cmd(0x80);
lcd_display("Enter number");
delay(1000);
lcd_cmd(0xC0);
keypad();delay(1000);lcd_cmd(0x01);
lcd_display("Dialing");
}
if(s3==1)
{
cnts=60;
while(cnts>=0)
{
lcd_cmd(0x01);
w=cnts/100;
y=cnts%100;
k=y/10;
n=y%10;
lcd_cmd(0x8D);
lcd_data(w+0x30);
delay(400);
lcd_cmd(0x8E);
lcd_data(k+0x30);
delay(4000);
lcd_cmd(0x8F);
lcd_data(n+0x30);
delay(4000);
if(s4==1)
{
	while(s4==1);
	cnts=cnts+60;delay(4000);
}
cnts--;
}
}
}
}


