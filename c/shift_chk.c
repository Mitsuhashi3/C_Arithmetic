/* C����ŃV�t�g���Z�̓�����m�F */
/* shift_chk.c */

#include<stdio.h>

int main(void){
	int a;
	unsigned int b;
	
	a = 0x80000000;
	b = 0x80000000;
	
	a = a >> 1;		/* a�͕����t���̐����Ȃ̂ŎZ�p�V�t�g�̈Ӗ��ɂȂ� */
	b = b >> 1;		/* b�͕����Ȃ��̐����Ȃ̂Ř_���V�t�g�̈Ӗ��ɂȂ� */
	
	printf("a = %x\n", a);
	printf("b = %x\n", b);
	
	return 0;	

}