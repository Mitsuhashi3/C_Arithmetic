/*文字列処理関数の練習 str_func.c*/
/*	strlen 文字列の長さ
	strcpy 文字列コピー
	strcat 文字列連結
	strcmp 文字列比較
*/

#include<stdio.h>
#include<string.h>

int main(void)
{

	char strin[101];
	char st_wk[31];
	char st1[] = "abc";
	char st2[] = "defg";
	char st3[] = "abc";
	int nagasa;
	int jg;
	
	/*入力した文字列の長さ表示*/
	printf("strin入力→");
	scanf("%s",strin);
	nagasa = strlen(strin);
	printf("strinの長さ = %d\n",nagasa);
	
	/*文字列のコピー*/
	strcpy(st_wk,st1);	/*後ろの文字列を前の領域にコピー*/
	printf("st_wk = %s\n",st_wk);
	
	/*文字列の連結*/
	strcat(st_wk,st2); /*st_wkに存在する文字列にst2の文字列を連結*/
	printf("st_wk = %s\n",st_wk);	
	
	/*文字列の比較*/
	/*	strcmp関数の戻り値は、0(ゼロ)の時が比較した2つの文字列が同じ
		0(ゼロ)以外は同じでなかったということ*/
	if(strcmp(st1,st2)==0){
		printf("st1とst2は同じ\n");
	}else{
		printf("st1とst2は違う\n");	
	}
	if(strcmp(st1,st3)==0){
		printf("st1とst3は同じ\n");
	}else{
		printf("st1とst3は違う\n");	
	}
	
	return 0;

}