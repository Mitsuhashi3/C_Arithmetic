/* �w���t�@�C��(19�w��)��ǂݍ���ŁA�Е������X�Ƃ���
   �A�����A���X�g�̐擪����o�͂���
   ���f�[�^���ǂ̂悤�ȏ��ł��A�w�ԍ����Ƀ��X�g���Ȃ�!!
   ���\�[�g�A���S���Y�����g���킯�ł͂Ȃ� */
/* eki04.c */
 
/*	���̓t�@�C�� : eki_rnd.csv, eki_srt.csv, eki_null.csv */ 

#include<stdio.h>
#include<stdlib.h>

/* �w�f�[�^��1�����ǂݍ��ނ��߂� �\���� EKI �̐錾
   �Е������X�g�Ȃ̂Ŏ��f�[�^�ւ̃|�C���^�������� */
 typedef struct list{
	int no;
	char name[31];
	struct list *next;	/* �|�C���^�� */
} EKI;

/* ���X�g�̐擪����Ō�̃f�[�^�܂ł̘A���o�͂���֐� */

/* �L�[�l���r���āA���X�g�̓K�؂Ȉʒu�Ƀf�[�^�}������֐� */


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
		
		/* ���X�g�̓K�؂Ȉʒu��sell�Ŏ������V�K�f�[�^��A�����鏈��(�n�܂�) */
		
		


		/* ���X�g�̓K�؂Ȉʒu��sell�Ŏ������V�K�f�[�^��A�����鏈��(�I���) */
		
		sell = (EKI *)malloc(sizeof(EKI));
		sts = fscanf(fp, "%d, %s", &sell->no, sell->name);
	}
	
	/* ���X�g�̐擪����Ō�̃f�[�^�܂ł̘A���o�͂���֐� */

	
	fcolse(fp);
	
	return 0;
}