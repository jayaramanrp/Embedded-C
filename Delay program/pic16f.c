#include<pic.h>//Header_file_for_PIC_microcontroller
#define led1 RB1
#define led2 RB2
void delay(unsigned int x)
{
while(x--);
}
main()
{
TRISB=0X00;
PORTB=0X00;

led1=1;
led2=0;
delay(50000);
led1=0;
led2=1;
delay(50000); 


}

//jayaramanrp