/* 駅名ファイル(19駅分)を読み込んで、両方向リスとして
   連結した後に、昇順か降順かを選んでリスト全体を出力する。
   
   ※データがどのような順でも、駅番号順にリストをつなぐ!!
   ※ソートアルゴリズムを使うわけではない */
/* eki05_lst.c */
/* 入力ファイル : eki_rnd.csv, eki_srt.csv, eki_null.csv */

#include <stdio.h>
#include <stdlib.h>

#define ASC 1
#define DESC 2

typedef struct list {
	int no;
	char name[31];
	struct list *prev;   /* 前データへのポインタ */
	struct list *next;   /* 次データへのポインタ */
} EKI;

int main(void)
{
	FILE *fp;
	char *f_name1 = "eki_rnd.csv";
	char *f_name2 = "eki_srt.csv";
	char *f_name3 = "eki_null.csv";
	EKI *top, *sell, *ptr;
	int sts, mode;
	
	/* 入力用ファイルのオープン */
	fp = fopen(f_name1, "r");
	if (fp == NULL) {
		printf("オープンエラー\n");
		return -1;
	}

	top = NULL;
	sell = (EKI *)malloc(sizeof(EKI));
	sts = fscanf(fp, "%d,%s", &sell->no, sell->name);
	while (sts != EOF) {
		/* リストの適切な位置にsellで示される新規データを連結する処理(始まり) */
		if (top == NULL) {    /* 最初の1件目 */
			top = sell;
			sell->next = NULL;
			sell->prev = NULL;
		} else {
			/* 新規データをどこにつなげばよいかを決定する処理 */
			ptr = top;
			while (ptr->next != NULL && ptr->no < sell->no) {
				ptr = ptr->next;
			}
			if (ptr->no < sell->no) {  /* リストの最後尾に挿入 */
				ptr->next = sell;
				sell->next = NULL;
				sell->prev = ptr;
			} else if (ptr != top) {   /* リストの途中に挿入 */
				sell->prev = ptr->prev;
				sell->next = ptr;
				ptr->prev->next = sell;
				ptr->prev = sell;
			} else {                   /* リストの先頭に挿入 */
				sell->prev = NULL;
				sell->next = top;
				top->prev = sell;
				top = sell;
			}
		}
		sell = (EKI *)malloc(sizeof(EKI));
		sts = fscanf(fp, "%d,%s", &sell->no, sell->name);
	}
	
	/* リストの先頭から最後のデータまで連続出力する処理 */

    printf("出力順を指定してください。（昇順=1, 降順=2）→ ");
    scanf("%d", &mode);
    while (mode != 1 && mode != 2) {
        printf("1か2を入力してください\n");
		printf("出力順を指定してください。（昇順=1, 降順=2）→ ");
		scanf("%d", &mode);
    }

	if (mode == ASC) {
		printf("昇順 駅リスト\n");
		for (ptr = top; ptr != NULL; ptr = ptr->next) {
			printf("%2d, %s\n", ptr->no, ptr->name);
		}
	} else {
		printf("降順 駅リスト\n");	
		for (ptr = top; ptr->next != NULL; ptr = ptr->next);  /* 一旦リストの最後尾まで進む */
		for (; ptr != NULL; ptr = ptr->prev) {
			printf("%2d, %s\n", ptr->no, ptr->name);
		}
	}
	
	fclose(fp);
	return 0;
}
	














