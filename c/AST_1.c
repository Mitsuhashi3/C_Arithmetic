/* AST_1.c */

#include <stdio.h>

int main(void)
{
	int max, i, j;
	
	printf("値を入力してください→");
	scanf("%d", &max);
	for (i = 1; i <= max; i ++ ) {
		for (j = 1; j <= max ; j ++) {
		    printf("*");
		}
	    printf("\n");
	}
	return 0;
}	