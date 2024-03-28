/* 駅名ファイル(19駅分)を読み込んで、両方向リスとして
連結した後に、昇順か降順かを選んでリスト全体を出力する。
   ※データがどのような順でも、駅番号順にリストをつなぐ!!
   ※ソートアルゴリズムを使うわけではない */
/* eki05_lst_func.c */
/* 入力ファイル : eki_rnd.csv, eki_srt.csv, eki_null.csv */

#include <stdio.h>
#include <stdlib.h>

#define ASC 1
#define DESC 2

typedef struct list {
	int no;
	char name[31];
	struct list *prev;	/* 前データへのポインタ */
	struct list *next;	/* 次のデータへのポインタ */
} EKI;

/* リストの先頭から最後のデータまで連続出力する関数 */
void list_print(EKI *);

/* キー値を比較して、リストの適切な位置にデータを挿入する関数 */
/* 引数はtopとsellを渡して、適切な位置にデータを挿入する。*/
void list_insert(EKI **, EKI *);

int main(void)
{
	FILE *fp;
	char *f_name1 = "eki_rnd.csv";
	char *f_name2 = "eki_srt.csv";
	char *f_name3 = "eki_null.csv";
	EKI *top, *sell, *ptr;
	int sts, mode;
	
	/* 入力用ファイルのオープン */
	fp = fopen(f_name1, "r"); /* f_name で示されるファイルをリードモードでオープン  [r] は読み取り*/
	if(fp == NULL){			 /* オープンできていない場合、fpにNULLが返されている */
		printf("オープンエラー\n");
		return -1;
	}
	
	top = NULL;
	sell = (EKI *)malloc(sizeof(EKI));
	sts = fscanf(fp, "%d,%s", &sell->no, sell->name);
	while(sts != EOF){
		/* リストの適切な位置にsellで示される新規データを連結する処理(始まり) */
		list_insert(&top,sell);
		sell = (EKI *)malloc(sizeof(EKI));
		sts = fscanf(fp, "%d,%s", &sell->no, sell->name);
	}
	
	/* リストの先頭から最後のデータまで連続で出力する処理 */
	
	/* 確実に1か2が入力されるまで繰り返す */
	/*
	printf("出力順を指定してください。(昇順=1, 降順=2) →");
	scanf("%d", &mode);
	*/
	
	fclose(fp);
	return 0;
}


void list_print(EKI *top)
{
	int mode;
	
	printf("出力順を指定してください。（昇順=1, 降順=2）→ ");
    scanf("%d", &mode);
    while (mode != 1 && mode != 2) {
        printf("1か2を入力してください\n");
		printf("出力順を指定してください。（昇順=1, 降順=2）→ ");
		scanf("%d", &mode);
    }

	if (mode == ASC) {
		printf("昇順 駅リスト\n");
		for (; ptr != NULL; ptr = ptr->next) {
			printf("%2d, %s\n", ptr->no, ptr->name);
		}
	} else {
		printf("降順 駅リスト\n");	
		for (; ptr->next != NULL; ptr = ptr->next);  /* 一旦リストの最後尾まで進む */
		for (; ptr != NULL; ptr = ptr->prev) {
			printf("%2d, %s\n", ptr->no, ptr->name);
		}
	}
	
}

void list_insert(EKI **top, EKI *sell)
{
	EKI *ptr, *ins_pt;
	
	if(*top == NULL){       /* リストの最初の1件目の登録 */
		*top = sell;
		sell->next = NULL;
	}else{
		/* 新規データをどこにつなげばよいかを決定する処理 
			決定するためにptr変数を活用し現状のリストの先頭から
			キー値(今回は駅番号)を比較していく */
		ptr = *top;
		while(ptr->next != NULL && ptr->no < sell -> no){
			ins_pt = ptr;	/* ins_ptにptrが書き替えられる前を保持 */
			ptr = ptr->next;
		}
		if(ptr->no < sell->no){ /* リストの最後尾に挿入 */
			ptr->next = sell;
			sell->next = NULL;
		}else if(ptr != *top){	/* リストの途中に挿入 */
			ins_pt->next = sell;
			sell->next = ptr;
		}else{					/* リストの先頭に挿入 */
			sell->next = *top;
			*top = sell;
		}
	}
}