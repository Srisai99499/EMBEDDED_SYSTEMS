#include<reg51.h>
void main(){

	TMOD = 0X01 ;//0000 0001 timer0-mode1 ,timer1-mode0
	TH0 = 0x00;
	TL0 = 0x00;
	TR0 =1;
	while(TF0==0);// wait for overflow  creates maximum delay 
	TR0=0;
	TR1=0;	
}
