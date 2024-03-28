/* pointer_2.c */
/* 値の交換 swap関数 */
/* main関数からswap関数を呼び出し、
   呼び出した先で値を交換して、その後
   main関数側で出力 */
   
#include<stdio.h>

void swap(int *, int *); /* 引数2つの内容値を交換 */


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