/* 駅名ファイル(19駅分)を読み込んで、片方向リスとして
   連結し、リストの先頭から出力する
   ※データをどのような順でも、駅番号順にリストをつなぐ!!
   ※ソートアルゴリズムを使うわけではない */
/* eki04.c */
 
/*	入力ファイル : eki_rnd.csv, eki_srt.csv, eki_null.csv */ 

#include<stdio.h>
#include<stdlib.h>

/* 駅データを1件分読み込むための 構造体 EKI の宣言
   片方向リストなので次データへのポインタ部がある */
 typedef struct list{
	int no;
	char name[31];
	struct list *next;	/* ポインタ部 */
} EKI;

/* リストの先頭から最後のデータまでの連続出力する関数 */

/* キー値を比較して、リストの適切な位置にデータ挿入する関数 */


int main(void)
{
	FILE *fp;
	char *f_name1 = "eki_rnd.csv";
	char *f_name2 = "eki_srt.csv";
	char *f_name3 = "eki_null.csv";
	EKI *top, *sell;
	int sts;
	
	top = NULL;
	sell = (EKI *)malloc(sizeof(EKI));
	sts = fscanf(fp, "%d,%s", &sell->no, sell->name);
	if(sts != EOF){
		top = sell;
	}
	while(sts != EOF){
		
		/* リストの適切な位置にsellで示される新規データを連結する処理(始まり) */
		
		


		/* リストの適切な位置にsellで示される新規データを連結する処理(終わり) */
		
		sell = (EKI *)malloc(sizeof(EKI));
		sts = fscanf(fp, "%d, %s", &sell->no, sell->name);
	}
	
	/* リストの先頭から最後のデータまでの連続出力する関数 */

	
	fcolse(fp);
	
	return 0;
}