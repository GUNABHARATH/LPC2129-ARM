#include<lpc21xx.h>
#define led 0xFF //P0.0 to P0.7 as Output Led
void delay(int);//Delay function Declaration

int main()
{
int i;
IODIR0 = led;
IOSET0 = led;//OFF the LED
while(1)
{
for(i=0;i<8;i++)
{
IOCLR0 = led & (1<<7-i);//LED ON
delay(1);//1 second Delay
IOSET0 = led;//LED OFF
delay(1);//1 second Delay
}
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
