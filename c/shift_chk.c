/* C言語でシフト演算の動作を確認 */
/* shift_chk.c */

#include<stdio.h>

int main(void){
	int a;
	unsigned int b;
	
	a = 0x80000000;
	b = 0x80000000;
	
	a = a >> 1;		/* aは符号付きの整数なので算術シフトの意味になる */
	b = b >> 1;		/* bは符号なしの整数なので論理シフトの意味になる */
	
	printf("a = %x\n", a);
	printf("b = %x\n", b);
	
	return 0;	

}