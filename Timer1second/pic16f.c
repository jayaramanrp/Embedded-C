//TIMER 0 
#include<pic.h>
void delay_1sec()
{
for(int i=0; i<=20; i++)
{
PS0=1;
PS1=1; //Settingn prescalar value
PS2=1;
PSA=0; //0-Enabling Timer mode; 1-WDT
T0SE=0; // sOURCEeDGE- rising edge
T0CS=0;  //cLOCKsOURCE- internal
TMR0=20; //LOAD VALUE
while(T0IF==0);
{
T0IF=0;
}
}
}
main()
{
TRISB=0X00;
PORTB=0X00;
delay_1sec();
PORTB=0X01;
delay_1sec();
}