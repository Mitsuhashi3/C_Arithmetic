/* 駅名ファイル(19駅分)を読み込んで、片方向リスとして
   連結し、リストの先頭から出力する
   ※データがどのような順でも、駅番号順にリストをつなぐ!!
   ※ソートアルゴリズムを使うわけではない */
/* eki04_lst.c */
/* 入力ファイル : eki_rnd.csv, eki_srt.csv, eki_null.csv */

#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int no;
	char name[31];
	struct list *next;
} EKI;


int main(void)
{
	FILE *fp;
	char *f_name1 = "eki_rnd.csv";
	char *f_name2 = "eki_srt.csv";
	char *f_name3 = "eki_null.csv";
	EKI *top, *sell, *ptr, *ins_pt;
	int sts;
	
	/* 入力用ファイルのオープン */
	fp = fopen(f_name1, "r");

	top = NULL;
	sell = (EKI *)malloc(sizeof(EKI));
	sts = fscanf(fp, "%d,%s", &sell->no, sell->name);

	while (sts != EOF) {
		
		/* リストの適切な位置にsellで示される新規データを連結する処理(始まり) */
		
		if(top == NULL){       /* リストの最初の1件目の登録 */
			top = sell;
			sell->next = NULL;
		}else{
			/* 新規データをどこにつなげばよいかを決定する処理 
				決定するためにptr変数を活用し現状のリストの先頭から
				キー値(今回は駅番号)を比較していく */
			ptr = top;
			while(ptr->next != NULL && ptr->no < sell -> no){
				ins_pt = ptr;	/* ins_ptにptrが書き替えられる前を保持 */
				ptr = ptr->next;
			}
			if(ptr->no < sell->no){ /* リストの最後備尾に挿入 */
				ptr->next = sell;
				sell->next = NULL;
			}else if(ptr != top){	/* リストの途中に挿入 */
				ins_pt->next = sell;
				sell->next = ptr;
			}else{					/* リストの先頭に挿入 */
				sell->next = top;
				top = sell;
			}
			
		}

		/* リストの適切な位置にsellで示される新規データを連結する処理(終わり) */
		
		sell = (EKI *)malloc(sizeof(EKI));
		sts = fscanf(fp, "%d,%s", &sell->no, sell->name);
	}
	
	/* リストの先頭から最後のデータまで連続出力する処理 */
	/* リストの先頭から出力 */
	printf("駅リスト\n");
	for(ptr = top; ptr != NULL; ptr = ptr->next){
		printf("%2d,%s\n", ptr->no, ptr->name);
	}
			
	
	fclose(fp);

	return 0;
}



/*
リストの挿入位置の判定基準

topがNULLのときは「最初の1件目」
topが示す番号より小さいときは「新たな先頭になる」

リストの途中から最後尾に登録されるケースでは、
リストの先頭からptr変数の示す位置より挿入データの番号が
大きくなる位置までptr変数を移動させ、
・ptr->nextがNULLの位置まで来ても、挿入データの番号が
  大きいときは、「最後尾」
・ptr->nextがNULLではないときは、ptrの示す1つ前、つまり「途中」

ptr -> next ->next = NULL:

*/