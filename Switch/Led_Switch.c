#include<lpc21xx.h>
#define led 0x02
#define Switch 0x01
void delay(int);//Delay function Declaration

int main()
{
IODIR0 = led;
IOSET0 = led;
while(1)
{
if((IOPIN0&0x01)==0)
{
IOCLR0 = led;//LED ON
delay(50);//delay for Switch Bouncing
//delay(100);
}
else
{
IOSET0 = led;//LED OFF
}
}
}

void delay(int second)//Delay function Definition
{
T0PR = 15000;//1ms=15000 , 1second =15000000
T0TCR = 0x01;
while(T0TC<second);
T0TCR = 0x03;
T0TCR = 0x00;
}
