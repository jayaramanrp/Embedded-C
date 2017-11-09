//TIMER 0 
#include<pic.h>
#define green RB0
#define orange RB1 
#define red RB2
void delay_60sec()
{
for(int i=0; i<=1200; i++)
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

void delay_10sec()
{
for(int i=0; i<=200; i++)
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

void delay_20sec()
{
for(int i=0; i<=400; i++)
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
while(1)
{
green=1;orange=0;
delay_60sec();
orange=1;green=0;red=0;
delay_10sec();
red=1;green=0;orange=0;
delay_20sec();
}
}
//jayaraman rp 