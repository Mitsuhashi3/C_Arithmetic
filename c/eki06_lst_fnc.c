/* 両方向リストの処理プログラム eki05_lst_func.c を
   環状リスト操作できるように改造
   
   ※出力形式は、起点となる駅から１週分
   ※起点となる駅の番号と出力方向(時計回り、反時計回り)を
   パラメータとして入力し、指定通りに出力
*/

/* eki06_lst_fnc.c */
/* 入力ファイル : eki_rnd.csv, eki_srt.csv, eki_null.csv */

#include <stdio.h>
#include <stdlib.h>

#define ASC 1
#define DESC 2

/* 駅データを１件分読み込むための 構造体 EKI の宣言
   片方向リストなので次データへのポインタ部がある */
typedef struct list{
	int no;
	char name[31];
	struct list *prev; /* 前データへのポインタ */
	struct list *next; /* 次データへのポインタ */
} EKI;

/* リストの先頭から再保までのデータまで連続出力する関数 */
void list_print(EKI *);

/* キー値を比較して、リストの適切な位置にデータを挿入する関数 */
void list_insert(EKI **, EKI *);

void list_ringchain(EKI *);

int main(void)
{
	FILE *fp;
	char *f_name1 = "eki_rnd.csv";
	char *f_name2 = "eki_srt.csv";
	char *f_name3 = "eki_null.csv";
	EKI *top, *ptr, *sell;
	int sts;
	
	/* 入力用ファイルのオープン */
	fp = fopen(f_name1, "r");
	if(fp == NULL) {
		printf("オープンエラー\n");
		return -1;
	}
	
	top = NULL;
	sell = (EKI *)malloc(sizeof(EKI));
	sts = fscanf(fp, "%d,%s", &sell->no, sell->name);
	
	while(sts != EOF) {
		/* リストの適切な位置にsellで示される新規データを連結する処理(始まり) */
		list_insert(&top, sell);
		
		sell = (EKI *)malloc(sizeof(EKI));
		sts = fscanf(fp, "%d,%s", &sell->no, sell->name);
	}
	
	/* 両方向ですべてつなぎ終えた後で、環状リストにするための
	   端の位置でデータどうしをつなぐ */
	   
	list_ringchain(top);
	
	list_print(top);
	
	fclose(fp);
	
	return 0;
}

void list_insert(EKI **top, EKI *sell)
{
	EKI *ptr;
	
	if(*top == NULL) { /* 最初の１件目 */
		*top = sell;
		sell->next = NULL;
		sell->prev = NULL;
	} else {
		/* 新規データをどこにつなげればよいかを決定する処理 */
		ptr = *top;
		while(ptr->next != NULL && ptr->no < sell->no) {
			ptr = ptr->next;
		}
		
		if(ptr->no < sell->no) { /* リストの最後尾に挿入 */
			ptr->next = sell;
			sell->next = NULL;
			sell->prev = ptr;
		} else if(ptr != *top) { /* リストの途中に挿入 */
			sell->prev = ptr->prev;
			ptr->prev->next = sell;
			ptr->prev = sell;
			sell->next = ptr;
		} else { /* リストの先頭に挿入 */
			sell->next = *top;
			*top = sell;
			sell->prev = NULL;
			ptr->prev = sell;
		}
	}
}

void list_ringchain(EKI *top)
{
	EKI *ptr;
	
	for(ptr = top; ptr->next != NULL; ptr = ptr->next){}
	
	ptr->next = top;
	top->prev = ptr;
}

void list_print(EKI *top)
{
	EKI *ptr;
	int cmd; /* 1:昇順 / 2:降順 */
	int beg; /* 開始位置 */
	
	printf("出力開始駅を入力(1～19) -> ");
	scanf("%d", &beg);
	
	while(beg < 1 || beg > 19) {
		printf("入力された数値は間違っています。\n\n");
		printf("出力開始駅を入力(1～19) -> ");
		scanf("%d", &beg);
	}
	
	printf("コマンド入力 (1は昇順, 2は降順) -> ");
	scanf("%d", &cmd);
	
	while(cmd != ASC && cmd != DESC) {
		printf("入力されたコマンドは間違っています。\n\n");
		printf("コマンド入力 (1は昇順, 2は降順) -> ");
		scanf("%d", &cmd);
	}
	
	if(top != NULL) {
		for(ptr = top; ptr->no != beg; ptr = ptr->next);
		
		if(cmd == ASC) {
			printf("\n%sから駅リスト(昇順)\n\n", ptr->name);
			
			do {
				printf("%2d, %s\n", ptr->no, ptr->name);
				ptr = ptr->next;
			} while(ptr->no != beg);
		} else if(cmd == DESC) {
			printf("\n%sから駅リスト(降順)\n\n", ptr->name);
			
			do {
				printf("%2d, %s\n", ptr->no, ptr->name);
				ptr = ptr->prev;
			} while(ptr->no != beg);
		}
	} else {
		printf("駅リストが存在しません\n");
	}
}