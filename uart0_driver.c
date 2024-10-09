#include"header.h"
void uart0_init(unsigned int baud){
	unsigned int a[]={15,60,30,15,15}, p,r;
	p=a[VPBDIV]*1000000;
	r=p/(16*baud);
	PINSEL0|=0x05;
	U0LCR=0x83;
	U0DLL=r&0xFF;
	U0DLM=(r>>8)&0xFF;
	U0LCR=0x03;
}
#define THRE ((U0LSR>>5)&1)
#define RDR (U0LSR &1)


void uart0_str(char *p){
	while(*p){
		U0THR=*p;
		while(THRE==0);
		p++;
	}
}
