/* ast_1.c*/

#include <stdio.h>

int main(void)
{
	int max, i, j;
	
	printf("値を入力してください→");
	scanf("%d", &max);
	for (j = 3; i <= max; i ++) {
		for (j = 3; j <= max; j ++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}