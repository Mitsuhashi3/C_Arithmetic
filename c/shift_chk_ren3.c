/* shift_chk_ren3.c */

#include<stdio.h>

int main(void){

	int i;
    unsigned int a, ma, omomi;
	
	printf("16進数8桁入力→");
	scanf("%x",&a);
	ma = a;
	
	/* シフトを使う */
	printf("2進パターン:");
	for(i = 1; i <= 32; i ++){
		if(0x80000000 & a){
			printf("1");
		}else{
			printf("0");
		}
		a <<= 1;
	}
	printf("\n");
	
	/* シフトを使わない方法 */
	printf("2進数パターン:");
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