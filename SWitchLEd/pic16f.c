#include<pic.h>//Header_file_for_PIC_microcontroller
main()
{
TRISB=0X00;//TRIS is a direction register Which decides the component to behave input or output
PORTB=0X00;//PORT is a value register which set the value 0 or 1 to the connected component
TRISC=0X01;//setting as input
PORTC=0X00;//Assigning value to 0
if(PORTC==1)//if value of the component reaches 1, it  will perform below operation 
{
PORTB=0X01;//Trun ON LED or SET value 1
}
else
{
PORTB=0X00;//Turn off or SET value Zero
}

}
//jayaramanrp