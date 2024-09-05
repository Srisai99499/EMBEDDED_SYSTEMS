#include<reg51.h>
void main(){

	TMOD = 0X02 ;//0000 0010 timer0-mode2 ,timer1-mode0
	TH0 = 0x10;
	TL0 = 0x00;
	TR0 =1;
	while(TF0==0);// wait for overflow 
	TR0=0;
	TR1=0;	
}
