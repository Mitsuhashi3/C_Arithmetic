/* shift_chk_ren1.c 
	������1��n�A�����Ă���r�b�g������B
	��n�͓��͒l�ŁA0�`32�͈̔͂œ��́B
*/
/* 32 �r�b�g �ȏ㒴������*/

#include<stdio.h>

int main(void){

	int a,n;
	int pat,kosu;
	
	
	printf("n�̒l����͂��Ă���������");
	scanf("%d",&n);
	
	a = 0x80000000;
	/* 0x ��16�i�� */
	
	a = a >> n;
	
	printf("a = %x\n", a);
	
	printf("\n");
	
	/* �����͔͉𓚁��� */
	printf("������̘A���������(0�`32) ��");
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