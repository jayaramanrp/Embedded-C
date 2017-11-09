#include<pic.h>
#define RS RB0
#define RW RB1
#define E RB2
void delay(unsigned int x)
{
while(x--);
}
void lcd_cmd(unsigned char a)
{
PORTD=a;
RW=0;//READ-0
RS=0;//COMMAND-1
E=0;
delay(500);
E=1;
}
void lcd_data(unsigned char b)
{
PORTD=b;
RS=1;//DATA-1
RW=0;
E=0;
delay(500);
E=1;
}
void lcd_word(const char *s)
{
for(int i=0; s[i]!=0;i++)
{
lcd_data(s[i]);
delay(500);
}
}
void lcd_init()
{
lcd_cmd(0x38); 
lcd_cmd(0x06);
lcd_cmd(0x0c);
lcd_cmd(0x01);
}
main()
{
TRISD=0X00;
TRISB=0X00;
PORTD=0X00;
while(1)
{
lcd_init();
delay(500);
lcd_cmd(0x83);
lcd_word("Welcome");
delay(5000);
}
}
//jayaraman rp