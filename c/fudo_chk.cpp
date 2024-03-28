#include <stdio.h>

typedef union float_chk {
	float true_data;
	long  byte_4;
} IEEE754;

void main(void)
{
	IEEE754 fudo;
	int i;

	printf("À”’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢¨");
	scanf("%f", &fudo.true_data);
	
	printf("%x\n", fudo.byte_4);
	
	for (i = 1; i <= 32; i ++) {
		if (0x80000000 & fudo.byte_4) { 
			printf("1");
		} else {
			printf("0");
		}
		fudo.byte_4 <<= 1;
	}
	printf("\n");
}