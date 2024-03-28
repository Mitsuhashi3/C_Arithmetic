/* �w���t�@�C��(19�w��)��ǂݍ���ŁA���������X�Ƃ���
�A��������ɁA�������~������I��Ń��X�g�S�̂��o�͂���B
   ���f�[�^���ǂ̂悤�ȏ��ł��A�w�ԍ����Ƀ��X�g���Ȃ�!!
   ���\�[�g�A���S���Y�����g���킯�ł͂Ȃ� */
/* eki05_lst_func.c */
/* ���̓t�@�C�� : eki_rnd.csv, eki_srt.csv, eki_null.csv */

#include <stdio.h>
#include <stdlib.h>

#define ASC 1
#define DESC 2

typedef struct list {
	int no;
	char name[31];
	struct list *prev;	/* �O�f�[�^�ւ̃|�C���^ */
	struct list *next;	/* ���̃f�[�^�ւ̃|�C���^ */
} EKI;

/* ���X�g�̐擪����Ō�̃f�[�^�܂ŘA���o�͂���֐� */
void list_print(EKI *);

/* �L�[�l���r���āA���X�g�̓K�؂Ȉʒu�Ƀf�[�^��}������֐� */
/* ������top��sell��n���āA�K�؂Ȉʒu�Ƀf�[�^��}������B*/
void list_insert(EKI **, EKI *);

int main(void)
{
	FILE *fp;
	char *f_name1 = "eki_rnd.csv";
	char *f_name2 = "eki_srt.csv";
	char *f_name3 = "eki_null.csv";
	EKI *top, *sell, *ptr;
	int sts, mode;
	
	/* ���͗p�t�@�C���̃I�[�v�� */
	fp = fopen(f_name1, "r"); /* f_name �Ŏ������t�@�C�������[�h���[�h�ŃI�[�v��  [r] �͓ǂݎ��*/
	if(fp == NULL){			 /* �I�[�v���ł��Ă��Ȃ��ꍇ�Afp��NULL���Ԃ���Ă��� */
		printf("�I�[�v���G���[\n");
		return -1;
	}
	
	top = NULL;
	sell = (EKI *)malloc(sizeof(EKI));
	sts = fscanf(fp, "%d,%s", &sell->no, sell->name);
	while(sts != EOF){
		/* ���X�g�̓K�؂Ȉʒu��sell�Ŏ������V�K�f�[�^��A�����鏈��(�n�܂�) */
		list_insert(&top,sell);
		sell = (EKI *)malloc(sizeof(EKI));
		sts = fscanf(fp, "%d,%s", &sell->no, sell->name);
	}
	
	/* ���X�g�̐擪����Ō�̃f�[�^�܂ŘA���ŏo�͂��鏈�� */
	
	/* �m����1��2�����͂����܂ŌJ��Ԃ� */
	/*
	printf("�o�͏����w�肵�Ă��������B(����=1, �~��=2) ��");
	scanf("%d", &mode);
	*/
	
	fclose(fp);
	return 0;
}


void list_print(EKI *top)
{
	int mode;
	
	printf("�o�͏����w�肵�Ă��������B�i����=1, �~��=2�j�� ");
    scanf("%d", &mode);
    while (mode != 1 && mode != 2) {
        printf("1��2����͂��Ă�������\n");
		printf("�o�͏����w�肵�Ă��������B�i����=1, �~��=2�j�� ");
		scanf("%d", &mode);
    }

	if (mode == ASC) {
		printf("���� �w���X�g\n");
		for (; ptr != NULL; ptr = ptr->next) {
			printf("%2d, %s\n", ptr->no, ptr->name);
		}
	} else {
		printf("�~�� �w���X�g\n");	
		for (; ptr->next != NULL; ptr = ptr->next);  /* ��U���X�g�̍Ō���܂Ői�� */
		for (; ptr != NULL; ptr = ptr->prev) {
			printf("%2d, %s\n", ptr->no, ptr->name);
		}
	}
	
}

void list_insert(EKI **top, EKI *sell)
{
	EKI *ptr, *ins_pt;
	
	if(*top == NULL){       /* ���X�g�̍ŏ���1���ڂ̓o�^ */
		*top = sell;
		sell->next = NULL;
	}else{
		/* �V�K�f�[�^���ǂ��ɂȂ��΂悢�������肷�鏈�� 
			���肷�邽�߂�ptr�ϐ������p������̃��X�g�̐擪����
			�L�[�l(����͉w�ԍ�)���r���Ă��� */
		ptr = *top;
		while(ptr->next != NULL && ptr->no < sell -> no){
			ins_pt = ptr;	/* ins_pt��ptr�������ւ�����O��ێ� */
			ptr = ptr->next;
		}
		if(ptr->no < sell->no){ /* ���X�g�̍Ō���ɑ}�� */
			ptr->next = sell;
			sell->next = NULL;
		}else if(ptr != *top){	/* ���X�g�̓r���ɑ}�� */
			ins_pt->next = sell;
			sell->next = ptr;
		}else{					/* ���X�g�̐擪�ɑ}�� */
			sell->next = *top;
			*top = sell;
		}
	}
}