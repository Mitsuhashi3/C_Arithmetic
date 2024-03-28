/* pointer_1.c */
/* 整数型変数へのポインタ */
/* ポインタ変数は、変数のアドレスを扱う変数
   使用するには、次の演算子を組み合わせて使う。
   & はアドレスを取り出す演算子
   * はポインタ変数の示すアドレスの内容値を扱う演算子
*/

#include<stdio.h>

int main(void)
{
	int a, b, ans;
	int *ptr1;	/* int * なので 整数型へのポインタ変数 */
	
	a = 10;
	b = 20;
	ans = a + b;
	printf("ansの内容 = %d\n", ans);
	
	ptr1 = &a;		/* 整数型へのポインタ変数 ptr1 に 変数a のアドレスを代入 */
	b    = *ptr1;	/* 変数b に 変数aの内容である 10が代入される */
	ans  = a + b;
	printf("ansの内容 = %d\n", ans);
	
	*ptr1 = 100;
	ans = a + b;
	printf("ansの内容 = %d\n", ans);
	
	ptr1  = &b;
	*ptr1 = 200;
	ans   = a + b;
	printf("ansの内容 = %d\n", ans);/*なぜ300?*
	
	return 0;
}
   