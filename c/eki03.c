/* 駅名ファイル(19駅分)を読み込んで、片方向リスとして
   連結し、リストの先頭から出力する
   (出力は読み込み順のまま) */
/* eki03.c */
 
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

int main(void)
{
	FILE *fp;
	char *f_name1 = "eki_rnd.csv";
	char *f_name2 = "eki_srt.csv";
	char *f_name3 = "eki_null.csv";
	EKI *top, *ptr, *sell;
	int sts;
	
	
	/* 入力用ファイルのオープン */
	fp = fopen(f_name1, "r"); /* f_name で示されるファイルをリードモードでオープン  [r] は読み取り*/
	if(fp == NULL){			 /* オープンできていない場合、fpにNULLが返されている */
		printf("オープンエラー\n");
		return -1;
	}

	/* リストをつなぎながらデータ読み込み */
		top = NULL;
		sell = (EKI *)malloc(sizeof(EKI));
		sts = fscanf(fp, "%d,%s", &sell->no, sell->name);
		if(sts != EOF){
			top = ptr = sell;
		}
		while(sts != EOF){
			sell = (EKI *)malloc(sizeof(EKI));
			sts = fscanf(fp, "%d, %s", &sell->no, sell->name);
			if(sts != EOF){
				ptr->next = sell;
				ptr = ptr->next;
			}else{
				ptr->next = NULL;
			}
		}
		
		/* リストの先頭から出力 */
		printf("駅リスト\n");
		for(ptr = top; ptr != NULL; ptr = ptr->next){
			printf("%2d,%s\n", ptr->no, ptr->name);
		}
		
	return 0;
}


/* main関数で使う、構造体へのポインタ変数
   top は リストの先頭
   ptr は リストの操作位置
   sellは 新規データの領域
*/

/* malloc関数は、指定サイズ分のメモリ領域を確保し
   確保した領域のアドレスを返す関数。
   プログラム内の表現では → sell = (EKI *)malloc(sizeof(EKI))
   駅構造体のサイズ分(sizeof(EKI))の領域を確保し、戻り値のアドレスを
   駅構造体へのポインタにキャスト(EKI *)している。
*/

/* -> は アロー演算子といい、構造体へのポインタ変数から、
   構造体のメンバ変数を示すための構造体操作専用の演算子
*/

/* ※※※ リスト構造で次のデータに進む意味の記述は ptr = ptr->next ※※※
   ptr変数自身に、自分が示しているデータのnextの値を代入
*/