#include<reg51.h>
void main(){

	TMOD = 0X03 ;//0000 0011 timer0-mode3 ,timer1-mode0
	TH0 = 0x00;
	TL0 = 0x00;
	TR0 =1;
	while(TF0==0);//  if TL0 is overflow Timer stop
	TR0=0;
	TR1=0;	
}