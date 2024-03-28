/* pointer_3.c */
/* ポインタ変数を活用し、main側で定義した文字列を
   呼び出して先で出力 */
   
#include<stdio.h>




void st_out(char *);						/* 文字列を先頭から最後まで1文字ずつ出力 */
void ch_out(char *, int);					/* 文字列のn番目の文字を1文字だけ出力 */
void stpt_out(char *, int, int);			/* 文字列の指定位置からn文字分を別の領域にコピー */
void stpt_cpy(char *, char *, int, int);	/* 文字列の指定位置からn文字分を別領域にコピー */
	
int main(void)
{
	char *str1 = "abcdefghijklmnopqrstuvwxy"; /* 26文字+Null('\n')文字で27バイトの領域 */
	char str2[11]; /* 文字列の部分をコピーの格納域(最大10文字) */
	
	st_out(str1);				/* str1全体の出力 */
	ch_out(str1,10);			/* str1のn番目の文字を出力 */
	stpt_out(str1, 5, 8);		/* str1の5番目から8文字分を出力 */
	stpt_cpy(str1, str2, 10, 5);/* str1の10番目から5文字分をstr2にコピー */
	st_out(str2);
	
	return 0;
}

void st_out(char *ptr)
{
	while (*ptr != '\0'){	/* ptr変数の示す1文字が	Null文字ではない間 */
		printf("%c", *ptr); /* ptr変数の示す先の1文字を出力 */
		ptr++;				/* ptr変数の示す先の1文字を出力 */
	}
	printf("\n");
	
}

void ch_out(char *ptr, int n)
{
	printf("%c\n", *(ptr + n)); /* ()を付ける付けないの演算の優先順注意!! */
}

void stpt_out(char *ptr,int n, int m)
{
	int i;
	for(i = 1; i <= m; i++){
		printf("%c", *(ptr + n));
		n++;
	}
	printf("\n");
}

void stpt_cpy(char *ptr1, char *ptr2, int n, int m)
{
	for(ptr1 += n; m > 0; m--){
		*ptr2 = *ptr1;
		ptr1 ++;
		ptr2 ++;
	}
	*ptr2 = '\0';
}