/* pointer_2.c */
/* �l�̌��� swap�֐� */
/* main�֐�����swap�֐����Ăяo���A
   �Ăяo������Œl���������āA���̌�
   main�֐����ŏo�� */
   
#include<stdio.h>

void swap(int *, int *); /* ����2�̓��e�l������ */


int main(void)
{
	int a, b;
	
	a = 5;
	b = 100;
	swap(&a, &b);
	printf("a = %d, b = %d\n", a, b);
	
	return 0;
}

void swap(int *val1, int *val2)
{
	int tmp;
	
	tmp  = *val1;
	*val1 = *val2;
	*val2 = tmp;
}