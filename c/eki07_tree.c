/* 駅名ファイル(19駅分)を読み込んで、駅番号をもとに、
   「左の子 ＜ 節 ＜ 右の子」のルールで登録した
   ２分探索木を作成し、根から左に巡回し、
   中間順で取り出す「バイナリソート」を行う */

/* eki07_tree.c */
/* 入力ファイル : eki_rnd.csv, eki_srt.csv, eki_null.csv */

#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	int no;
	char name[31];
	struct tree *left;
	struct tree *right;
} EKI;

int data_entry(FILE *, EKI *);   /* 入力ファイルから１件読む */
void tree_insert(EKI *, EKI *);  /* 木の入り口(根・ルート)のアドレスと、登録したい
                                    データのアドレスを渡すと適切な位置に登録 */
void tree_print(EKI *);          /* 木に登録されたデータを駅番号の昇順に出力 */

int main(void)
{
	FILE *fp;
	char *f_name1 = "eki_rnd.csv";
	char *f_name2 = "eki_srt.csv";
	char *f_name3 = "eki_null.csv";
	EKI *root, *sell;
	int sts;
	
	/* 入力用ファイルのオープン */
	fp = fopen(f_name1, "r");
	if (fp == NULL) {
		printf("オープンエラー\n");
		return -1;
	}
	
	root = NULL;
	sell = (EKI *)malloc(sizeof(EKI));
	sts = data_entry(fp, sell);
	
	while (sts != EOF) {
		if (root == NULL) {
			root = sell;				/* １件目の登録 */
		} else {
			tree_insert(root, sell);    /* ２件目以降の登録 */
		}
		sell = (EKI *)malloc(sizeof(EKI));
		sts = data_entry(fp, sell);
	}
	/* 木に登録されたデータの出力処理呼び出し */
	printf("駅リスト\n");
	if (root != NULL) {
		tree_print(root);   /* バイナリソート(中間順取り出し)処理呼び出し */
	}
		
	return 0;
}

int data_entry(FILE *fp, EKI *sell)
{
	int sts;
	
	sts = fscanf(fp, "%d,%s", &sell->no, sell->name);
	sell->left = NULL;
	sell->right = NULL;
	return sts;
}

void tree_insert(EKI *ptr, EKI *sell)
{
	if (ptr->no > sell->no) {
		if (ptr->left != NULL) {            /* 左の子として登録できるかできないかの振り分け */
			tree_insert(ptr->left, sell);   /* 左部分木に進む(再帰呼び出し) */
		} else {
			ptr->left = sell;               /* 左の子として登録 */
		}
	} else {
		if (ptr->right != NULL) {           /* 右の子として登録できるかできないかの振り分け */
			tree_insert(ptr->right, sell);  /* 右部分木に進む(再帰呼び出し) */
		} else {
			ptr->right = sell;              /* 右の子として登録 */
		}
	}
}

void tree_print(EKI *ptr)
{
	if (ptr != NULL) {
		tree_print(ptr->left);
		printf("%2d, %s\n", ptr->no, ptr->name);
		tree_print(ptr->right);
	}
}