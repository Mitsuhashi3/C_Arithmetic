/* 10�~10�̗̈��1�`3�̗����𔭐������A
	�w����W�̎���(�㉺���E)�œ����l���A�����镔����
	0�œh��Ԃ�
*/
/* fill_prg.c */
 
#include<stdio.h>
#include<stdlib.h>

#define A_MAX 10

void rnd_set(int *, int *);
void ary_print(int *, int );
void fill_zero(int, int, int, int [A_MAX][A_MAX]);

void main(void)
{
	int ary[A_MAX][A_MAX];
	int x, y;
	
	srand(time(NULL));
	rnd_set(ary[0], &ary[A_MAX-1][A_MAX-1]);
	ary_print(ary[0], A_MAX);
	printf("���W����\n(x, y)��");
	scanf("%d,%d", &x, &y);
	while(x < 0 || x > A_MAX-1 || y < 0 || y > A_MAX-1){
		printf("�͈͊O�ł��ē���\n");
		printf("���W����\n(x,y)��");
		scanf("%d, %d", &x, &y);
	}
	/* �����ɓh��Ԃ������������A�h��Ԃ��������Ăяo���Ȃ� */
	fill_zero(x, y, ary[y][x], ary);
	ary_print(ary[0], A_MAX);
	
}

void rnd_set(int *ptr, int *p_end)
{
	for(; ptr <= p_end; ptr ++){
		*ptr = rand() / 32768.0 * 3 + 1;
	}
}

void ary_print(int *ptr, int max)
{
	int i, j;
	
	printf("  0 1 2 3 4 5 6 7 8 9\n");
		for(i = 0; i < max; i ++){
		printf("%d ", i);
		for(j = 1; j <= max; j ++, ptr ++){
			printf("%d ", *ptr);
		}
		printf("\n");
	}

}

void fill_zero(int x, int y, int val, int ary[A_MAX][A_MAX])
{
	ary[y][x] = 0;
	if(y > 0 && ary[y - 1][x] == val){
		fill_zero(x, y - 1, val, ary);
	}
	if(x > 0 && ary[y][x - 1] == val){
		fill_zero(x - 1, y, val, ary);
	}
	if(y < A_MAX - 1 && ary[y + 1][x] == val){
		fill_zero(x, y + 1, val, ary);
	}
	if(x < A_MAX - 1 && ary[y][x + 1] == val){
		fill_zero(x + 1, y, val, ary);
	}
}