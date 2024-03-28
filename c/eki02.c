/* 駅名ファイル(19駅分)を読み込んで、
   19駅分の構造体配列に格納し、駅番号順に
   ソートされた状態で出力する */
/* eki02.c */
/* 
	入力ファイル : eki_rnd.csv, eki_srt.csv 
	出力ファイル : eki_srtnew.csv
*/
   
#include<stdio.h>

/* 駅データを1件分読み込むための 構造体 EKI の宣言 */
typedef struct{
	int no;			/* 数字 */
	char name[31];	/* 文字 */
} EKI;

int main(void)
{
	FILE *fp1, *fp2;
	char *f_name1 = "eki_rnd.csv";		/* eki_srt.csvでも試す */
	char *f_name2 = "eki_srtnew.csv";	/*  */
	EKI data[19], tmp;	/* 19行 */
	int sts, idx, i, j;
	
	fp1 = fopen(f_name1, "r"); /* f_name で示されるファイルをリードモードでオープン  [r] は読み取り*/
	if(fp1 == NULL){			 /* オープンできていない場合、fpにNULLが返されている */
		printf("オープンエラー\n");
		return -1;
	}
	
	/* 構造体配列への読み込みループ */
	idx = 0;
	sts = fscanf(fp1, "%d,%s", &data[0].no, data[0].name);
	while(sts != EOF){
		idx ++;
		sts = fscanf(fp1, "%d,%s", &data[idx].no, data[idx].name);
	}
	
	/* 構造体配列を駅番号をキーとして昇順に並べ替える(挿入ソート) */
	for(i = 1; i <= 18; i ++){
		tmp = data[i];
		j = i;
		while(j > 0 && data[j - 1].no > tmp.no){
			data[j] = data[j - 1];
			j --;
		}
		data[j] = tmp;
	}
	
	/* 出力用ファイルのオープン */
	fp2 = fopen(f_name2, "w");
	if(fp2 == NULL){
		printf("オープンエラー\n");
		return -1;
	}
	
	/* 構造体配列の内容を出力ファイルに書き出す処理 */
	for(idx = 0; idx <= 18; idx ++){
		fprintf(fp2, "%d,%s\n", data[idx].no, data[idx].name);
	}
	
	
	fclose(fp1);
	fclose(fp2);
	return 0;
	
}