/* shift_chk_ren2.c 
	右から1がn個連続しているビット列を作る。
	※nは入力値で、0～32の範囲で入力。
*/

#include<stdio.h>

int main(void){

	unsigned int a;
    int n;
	
	printf("右からの連続数を入力(0～32) →");
	scanf("%d",&n);
	
	a = 0xffffffff;
	/* 0x は16進数 */
	
	if(n == 0){
		a = 0;
		printf("00000000\n");
	}else{
		a >>= (32 - n);
		printf("%08x\n", a);
	}
	
	
	return 0;
	

}