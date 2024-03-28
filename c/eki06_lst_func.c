/* 両方方向リスト 
eki06_lst_func.c 
*/
/* 入力ファイル : eki_rnd.csv, eki_srt.csv, eki_null.csv */

#include <stdio.h>
#include <stdlib.h>

#define R_TURN
#define L_TURN

typedef struct list {
	int no;
	char name[31];
	struct list *prev;	/* 前データへのポインタ */
	struct list *next;	/* 次のデータへのポインタ */
} EKI;

void list_insert(EKI **, EKI *);
void list_print(EKI *);
void list_ringchain(EKI *);

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
}

void list_insert(EKI **top, EKI *sell)
{
	EKI *ptr;
	
	if(*top == NULL){       /* リストの最初の1件目の登録 */
		*top = sell;
		sell->next = NULL;
		sell->prev = NULL;
	}else{
		/* 新規データをどこにつなげばよいかを決定する処理 
			決定するためにptr変数を活用し現状のリストの先頭から
			キー値(今回は駅番号)を比較していく */
		ptr = *top;
		while(ptr->next != NULL && ptr->no < sell->no){
			ptr = ptr->next;
		}
		if(ptr->no < sell->no){ /* リストの最後尾に挿入 */
			ptr->next = sell;
			sell->next = NULL;
			sell->prev = ptr;
		}else if(ptr != *top){	/* リストの途中に挿入 */
			sell->prev = ptr->prev;
			sell->next = ptr;
			ptr->prev->next = sell;
			ptr->ptr = sell;
		}else{					/* リストの先頭に挿入 */
			sell->prev = NULL;
			sell->next = *top;
			(*top)->prev = sell;
			*top = sell;
		}
	}
}


void list_ringchain(EKI *top)
{
	EKI *ptr;
	
	/* ptrを両方向リストの最終データまで進める */
	for(ptr = top; ptr->next != NULL; ptr = ptr->next);
	
	top->prev = ptr;
	ptr->next = top;
}


void list_print(EKI *top)
{
	EKI *ptr;
	int mode, beg;
	
	printf("出力開始駅の番号を指定してください。(1～19) →");
	scanf("%d", &beg);
	
	while(beg < 1 || beg > 19){
		printf("1～19を入力してください\n");
		printf("出力開始駅の番号を指定してください。(1～19)\n");
		scanf("%d", &beg);
	}
	
	printf("出力順を指定してください。(時計周り=1, 反時計回り=2) →");
	scanf("%d", &mode);	
	while(mode != R_TURN && mode != L_TURN){
		printf("1か2を入力してください\n");
		printf("出力順を指定してください。(時計周り=1,反時計回り=2) →");
		scanf("%d", &mode);
	}
	
	/* 指定の駅番号までptrを進める */
	if(top != NULL){
		for(ptr = top; ptr->no != beg; ptr = ptr->next);
	
		if(mode == R_TURN){
			printf("%sから時計周り 駅リスト\n", ptr->name);
		
			do{
				printf("%2d, %s\n", ptr->no, ptr->name);
				ptr = ptr->next;
			}while(ptr->no != beg);
		}else{
			printf("%sから反時計周り 駅リスト\n", ptr->name);
			do{
				printf("%2d, %s\n", ptr->no, ptr->name);
				ptr = ptr->prev;
			}while(ptr->no != beg);
		}
	}else{
		printf("駅リストが存在しません!!\n");
	}
	
}