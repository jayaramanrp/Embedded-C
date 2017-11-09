//Analog to digital converter
#include<pic.h>
#define RS RC0
#define RW RC1
#define E RC2
unsigned int a,b,c,d,input=0;
void delay(unsigned int x)
{ while(x--);
}
void lcd_data(unsigned int a)
{
PORTB=a;
RS=1;
E=1;
RW=0;

delay(1000);
E=0;
}

void lcd_cmd(unsigned int b)
{
PORTB=b;
RS=0;
E=1;
RW=0;

delay(1000);
E=0;
}
void lcd_init()
{
lcd_cmd(0X38);
lcd_cmd(0X0c);
lcd_cmd(0X06);
lcd_cmd(0X01);
}
void adc_conversion()
{
/* Inorder to activate adc FEATURE ADCON0,ADCON1 must be considered
ADCON0(A/D CONTROL REGISTER 0)-For control operation */
CHS2=0;
CHS1=0; // To select channal (Refer DATA sheet)
CHS0=0;
ADON=1; // To ON A/D bit
ADCON0=ADCON0|0X04; // To enable DONE bit i.e GO/DONE=1
delay(5000);
input=ADRESH<<8;        // converting input within limit
input=(input+ADRESL)/2.045;
a=input/100; 
b=input%100;
c=b/10;
d=b%10;
lcd_cmd(0xc0);
lcd_data(a+0x30);
lcd_data(c+0x30);
lcd_data(d+0x30);
}
main()
{
TRISA=0X01; // making RA0 pin as input
TRISC=0X00;
PORTC=0X00;
TRISB=0X00; 
PORTB=0X00;
ADCON0=0X40;   //selecting clock frequency
ADCON1=0X82;   //bit7- Right justified bit1-making port A pin to act analog
lcd_init();
delay(500);

while(1)
{
lcd_cmd(0x80);
lcd_data('A');lcd_data('D');lcd_data('C');
adc_conversion();
}
}
//jayaraman rp 










