/* �w���t�@�C��(19�w��)��ǂݍ���ŁA���������X�Ƃ���
   �A��������ɁA�������~������I��Ń��X�g�S�̂��o�͂���B
   
   ���f�[�^���ǂ̂悤�ȏ��ł��A�w�ԍ����Ƀ��X�g���Ȃ�!!
   ���\�[�g�A���S���Y�����g���킯�ł͂Ȃ� */
/* eki05_lst.c */
/* ���̓t�@�C�� : eki_rnd.csv, eki_srt.csv, eki_null.csv */

#include <stdio.h>
#include <stdlib.h>

#define ASC 1
#define DESC 2

typedef struct list {
	int no;
	char name[31];
	struct list *prev;   /* �O�f�[�^�ւ̃|�C���^ */
	struct list *next;   /* ���f�[�^�ւ̃|�C���^ */
} EKI;

int main(void)
{
	FILE *fp;
	char *f_name1 = "eki_rnd.csv";
	char *f_name2 = "eki_srt.csv";
	char *f_name3 = "eki_null.csv";
	EKI *top, *sell, *ptr;
	int sts, mode;
	
	/* ���͗p�t�@�C���̃I�[�v�� */
	fp = fopen(f_name1, "r");
	if (fp == NULL) {
		printf("�I�[�v���G���[\n");
		return -1;
	}

	top = NULL;
	sell = (EKI *)malloc(sizeof(EKI));
	sts = fscanf(fp, "%d,%s", &sell->no, sell->name);
	while (sts != EOF) {
		/* ���X�g�̓K�؂Ȉʒu��sell�Ŏ������V�K�f�[�^��A�����鏈��(�n�܂�) */
		if (top == NULL) {    /* �ŏ���1���� */
			top = sell;
			sell->next = NULL;
			sell->prev = NULL;
		} else {
			/* �V�K�f�[�^���ǂ��ɂȂ��΂悢�������肷�鏈�� */
			ptr = top;
			while (ptr->next != NULL && ptr->no < sell->no) {
				ptr = ptr->next;
			}
			if (ptr->no < sell->no) {  /* ���X�g�̍Ō���ɑ}�� */
				ptr->next = sell;
				sell->next = NULL;
				sell->prev = ptr;
			} else if (ptr != top) {   /* ���X�g�̓r���ɑ}�� */
				sell->prev = ptr->prev;
				sell->next = ptr;
				ptr->prev->next = sell;
				ptr->prev = sell;
			} else {                   /* ���X�g�̐擪�ɑ}�� */
				sell->prev = NULL;
				sell->next = top;
				top->prev = sell;
				top = sell;
			}
		}
		sell = (EKI *)malloc(sizeof(EKI));
		sts = fscanf(fp, "%d,%s", &sell->no, sell->name);
	}
	
	/* ���X�g�̐擪����Ō�̃f�[�^�܂ŘA���o�͂��鏈�� */

    printf("�o�͏����w�肵�Ă��������B�i����=1, �~��=2�j�� ");
    scanf("%d", &mode);
    while (mode != 1 && mode != 2) {
        printf("1��2����͂��Ă�������\n");
		printf("�o�͏����w�肵�Ă��������B�i����=1, �~��=2�j�� ");
		scanf("%d", &mode);
    }

	if (mode == ASC) {
		printf("���� �w���X�g\n");
		for (ptr = top; ptr != NULL; ptr = ptr->next) {
			printf("%2d, %s\n", ptr->no, ptr->name);
		}
	} else {
		printf("�~�� �w���X�g\n");	
		for (ptr = top; ptr->next != NULL; ptr = ptr->next);  /* ��U���X�g�̍Ō���܂Ői�� */
		for (; ptr != NULL; ptr = ptr->prev) {
			printf("%2d, %s\n", ptr->no, ptr->name);
		}
	}
	
	fclose(fp);
	return 0;
}
	














