//SPI PROTOCOL
//SLAVE
#include<pic.h>
#define led RB7
#define sw RD0
unsigned int a;
void delay(unsigned int x)
{
while(x--);
}
main()
{
TRISB=0X00;
PORTB=0X00;
TRISC=0X18; //SDI,SCL as input
PORTC=0X00;  
TRISD=0X01;
PORTD=0X00;
SSPSTAT=0X80; 
SSPEN=1;
SSPM3=0;
SSPM2=1;  //SPI MODE; To disable SS(Slave Select)Since only one slave is used here
SSPM1=0;
SSPM0=1;  
while(1)
{
 if(SSPBUF=='5')
 led=1;
 else
 led=0;
if(sw==1)
 {
 a='1';
 SSPBUF=a;
 while(SSPIF==0);
 SSPIF=0;
}
else
 {
 a='2';
 SSPBUF=a;
 while(SSPIF==0);
 SSPIF=0;
}

}

}
//jayaraman rp