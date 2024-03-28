/* 駅名ファイルを読み込んで順に表示 */
/* eki01.c */

#include<stdio.h>

/* 駅データを1件分読み込むための 構造体 EKI の宣言 */
typedef struct{
	int no;			/* 数字 */
	char name[31];	/* 文字 */
} EKI;

int main(void)
{
	FILE *fp; /* ファイル制御変数 */
	char *f_name = "eki_srt.csv"; /* ←ファイル名は他のものにも変更して試す */
	EKI data; /* 構造体EKI型の変数dataの宣言 */
	int sts;  /* ファイル読み込みステータス用変数 */
	
	fp = fopen(f_name, "r"); /* f_name で示されるファイルをリードモードでオープン  [r] は読み取り*/
	if(fp == NULL){			 /* オープンできていない場合、fpにNULLが返されている */
		printf("オープンエラー\n");
		return -1;
	}
	
	
	/* ファイル内容を読み込んで表示する処理 */
	sts = fscanf(fp, "%d,%s", &data.no, data.name);
	while(sts != EOF){
		printf("%2d, %s\n", data.no, data.name);		
		sts = fscanf(fp, "%d,%s", &data.no, data.name);

	}
	
	
	fclose(fp);
	return 0;
}