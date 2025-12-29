#include<lpc21xx.h>
#define led 0x01 //P0.0 as Output Led
void delay(int);//Delay function Declaration

int main()
{
IODIR0 = led;
IOSET0 = led;//OFF the LED
while(1)
{
IOCLR0 = led;//LED ON
delay(1);//1 second Delay
IOSET0 = led;//LED OFF
delay(1);//1 second Delay
}
}

void delay(int second)//Delay function Definition
{
T0PR = 15000000;//1ms=15000 , 1second =15000000
T0TCR = 0x01;
while(T0TC<second);
T0TCR = 0x03;
T0TCR = 0x00;
}
