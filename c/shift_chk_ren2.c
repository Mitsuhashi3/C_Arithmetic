/* shift_chk_ren2.c 
	�E����1��n�A�����Ă���r�b�g������B
	��n�͓��͒l�ŁA0�`32�͈̔͂œ��́B
*/

#include<stdio.h>

int main(void){

	unsigned int a;
    int n;
	
	printf("�E����̘A���������(0�`32) ��");
	scanf("%d",&n);
	
	a = 0xffffffff;
	/* 0x ��16�i�� */
	
	if(n == 0){
		a = 0;
		printf("00000000\n");
	}else{
		a >>= (32 - n);
		printf("%08x\n", a);
	}
	
	
	return 0;
	

}