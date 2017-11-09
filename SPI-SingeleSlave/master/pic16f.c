//SPI PROTOCOL
//MASTER
#include<pic.h>
#define led RD0 
#define sw RB0
unsigned int a;
void delay(unsigned int x)
{
while(x--);
}
main()
{
TRISB=0X01; //making RB0 as input
PORTB=0X00;
TRISD=0X00;
PORTD=0X00;
TRISC=0X10; // SDI as input
PORTC=0X00;
SSPSTAT=0X80; //SMP bit=1
SSPEN=1;
 SSPM3=0;
 SSPM2=0;
 SSPM1=0;
 SSPM0=0;
 

while(1)
{
if(SSPBUF=='1')
{led=1;
delay(5000);
}
else
{
led=0;
delay(500);
}
if(sw==1)
{
a='5';
SSPBUF=a;
while(SSPIF==0);
SSPIF=0;
}
else
{
a='4';
SSPBUF=a;
while(SSPIF==0);
SSPIF=0;
}
}
}