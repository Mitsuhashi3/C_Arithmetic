/* shift_chk_ren3.c */

#include<stdio.h>

int main(void){

	int i;
    unsigned int a, ma, omomi;
	
	printf("16�i��8�����́�");
	scanf("%x",&a);
	ma = a;
	
	/* �V�t�g���g�� */
	printf("2�i�p�^�[��:");
	for(i = 1; i <= 32; i ++){
		if(0x80000000 & a){
			printf("1");
		}else{
			printf("0");
		}
		a <<= 1;
	}
	printf("\n");
	
	/* �V�t�g���g��Ȃ����@ */
	printf("2�i���p�^�[��:");
	omomi = 2147483648;
	for(i = 1; i <= 32; i ++){
		if(ma >= omomi){
			printf("1");
			ma -= omomi;
		}else{
			printf("0");
		}
	}
	
	printf("a = %x\n", a);

	
	return 0;
	

}