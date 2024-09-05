#include<reg51.h>
void main(){

	TMOD = 0X00 ;//0000 0000 timer0-mode0 ,timer1-mode0
	TH0 = 0x00;
	TL0 = 0x00;
	TR0 =1;
	while(TF0==0);// wait for overflow 11111111 00011111
	TR0=0;
	TR1=0;	
}
