/* shift_chk_ren1.c 
	左から1がn個連続しているビット列を作る。
	※nは入力値で、0～32の範囲で入力。
*/
/* 32 ビット 以上超えたら*/

#include<stdio.h>

int main(void){

	int a,n;
	int pat,kosu;
	
	
	printf("nの値を入力してください→");
	scanf("%d",&n);
	
	a = 0x80000000;
	/* 0x は16進数 */
	
	a = a >> n;
	
	printf("a = %x\n", a);
	
	printf("\n");
	
	/* ↓↓模範解答↓↓ */
	printf("左からの連続数を入力(0～32) →");
	scanf("%d",&kosu);
	
	if(kosu == 0){
		pat = 0;
		printf("00000000\n");
	}else{
		pat = 0x80000000;
		pat >>= (kosu - 1);
		printf("%x\n", pat);
	}
	
	
	
	return 0;
	

}