/* スタック構造を活用して逆ポーランド式の計算を行うプログラム */
/* rev_pol.c */
#include<stdio.h>

int main(void)
{
	char shiki[] = "abc+*";
	int  kou[]   = {5, 3, 2};
	int  stack[100];
	int  sid, kid, sp;
	int  ans, tmp1, tmp2;
	
	kid = 0;
	sp  = 0;
	for(sid = 0; shiki[sid] != '\0'; sid ++){
		if( shiki[sid]  != '+' && shiki[sid] != '-' &&
			shiki[sid]  != '*' && shiki[sid] != '/'){
				stack[sp] = kou[kid];
				sp ++;
				kid ++;
		}else{
			sp --;
			tmp2 = stack[sp];
			sp --;
			tmp1 = stack[sp];
			switch (shiki[sid]){
				case '+': ans = tmp1 + tmp2;
						break;
				case '-': ans = tmp1 - tmp2;
						break;
				case '*': ans = tmp1 * tmp2;
						break;
				case '/': ans = tmp1 / tmp2;
						break;
			}
			stack[sp] = ans;
			sp ++;
		}
	}
	sp --;
	printf("計算結果 = %d\n", stack[sp]);

	
	return 0;
}