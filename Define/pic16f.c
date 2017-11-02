#include<pic.h>
//Header_file_for_PIC_microcontroller

#define sw RC0
//define-which breaks the program into readable 

#define led RB0
//Easy to assign without much effort

/*From this program onwards I'm going to use this define function
 for all the upcoming programs*/

main()
{
/*TRIS, PORT require the value in 16bit format
where as Defined one like led,sw require 0 or 1*/

TRISB=0X00;
//TRIS is a direction register Which decides the component to behave input or output

PORTB=0X00;
//PORT is a value register which set the value 0 or 1 to the connected component

TRISC=0X01;
//setting as input

PORTC=0X00;
//Assigning value to 0
if(sw==1)//if value of the component reaches 1, it  will perform below operation 
{
led=1;//Trun ON LED or SET value 1
}
else
{
led=0;//Turn off or SET value Zero
}

}
//jayaramanrp