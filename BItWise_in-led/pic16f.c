#include<pic.h>
void delay(unsigned int x)
{
while(x--);
}
main()
{
TRISB=0X00;
PORTB=0X80;//IF_LAST_LED_TO_1ST__BITWISE_OPERATOR
for(int i=0;i<=8;i++)
{
PORTB=PORTB>>1;
delay(5000);
}
}
