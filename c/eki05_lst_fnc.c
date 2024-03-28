/* �w���t�@�C��(19�w��)��ǂݍ���ŁA���������X�g�Ƃ���
   �A��������ɁA�������~������I��Ń��X�g�S�̂��o�͂���B
   
   ���f�[�^���ǂ̂悤�ȏ��ł��A�w�ԍ����Ƀ��X�g���Ȃ�
   �\�[�g�A���S���Y�����g���킯�ł͂Ȃ� */
/* eki05_lst_fnc.c */
/* ���̓t�@�C�� : eki_rnd.csv, eki_srt.csv, eki_null.csv */

#include <stdio.h>
#include <stdlib.h>

#define ASC 1
#define DESC 2

/* �w�f�[�^���P�����ǂݍ��ނ��߂� �\���� EKI �̐錾
   �Е������X�g�Ȃ̂Ŏ��f�[�^�ւ̃|�C���^�������� */
typedef struct list{
	int no;
	char name[31];
	struct list *prev; /* �O�f�[�^�ւ̃|�C���^ */
	struct list *next; /* ���f�[�^�ւ̃|�C���^ */
} EKI;

/* ���X�g�̐擪����ĕۂ܂ł̃f�[�^�܂ŘA���o�͂���֐� */
void list_print(EKI *);

/* �L�[�l���r���āA���X�g�̓K�؂Ȉʒu�Ƀf�[�^��}������֐� */
/* ������top */
void list_insert(EKI **, EKI *);

int main(void)
{
	FILE *fp;
	char *f_name1 = "eki_rnd.csv";
	char *f_name2 = "eki_srt.csv";
	char *f_name3 = "eki_null.csv";
	EKI *top, *ptr, *sell;
	int sts;
	
	/* ���͗p�t�@�C���̃I�[�v�� */
	fp = fopen(f_name1, "r");
	if(fp == NULL) {
		printf("�I�[�v���G���[\n");
		return -1;
	}
	
	top = NULL;
	sell = (EKI *)malloc(sizeof(EKI));
	sts = fscanf(fp, "%d,%s", &sell->no, sell->name);
	
	while(sts != EOF) {
		/* ���X�g�̓K�؂Ȉʒu��sell�Ŏ������V�K�f�[�^��A�����鏈��(�n�܂�) */
		list_insert(&top, sell);
		
		sell = (EKI *)malloc(sizeof(EKI));
		sts = fscanf(fp, "%d,%s", &sell->no, sell->name);
	}
	
	list_print(top);
	
	fclose(fp);
	
	return 0;
}

void list_print(EKI *ptr)
{
	int cmd; /* 1:���� / 2:�~�� */
	
	printf("�R�}���h���� (1�͏���, 2�͍~��) -> ");
	scanf("%d", &cmd);
	
	while(cmd != ASC && cmd != DESC) {
		printf("���͂��ꂽ�R�}���h�͊Ԉ���Ă��܂��B\n\n");
		printf("�R�}���h���� (1�͏���, 2�͍~��) -> ");
		scanf("%d", &cmd);
	}
	
	if(cmd == ASC) {
		printf("\n�w���X�g(����)\n\n");
		
		for(; ptr != NULL; ptr = ptr->next) {
			printf("%2d, %s\n", ptr->no, ptr->name);
		}
	} else if(cmd == DESC) {
		printf("\n�w���X�g(�~��)\n\n");
		
		for(; ptr->next != NULL; ptr = ptr->next);
		for(; ptr != NULL; ptr = ptr->prev) {
			printf("%2d, %s\n", ptr->no, ptr->name);
		}
	}
}

void list_insert(EKI **top, EKI *sell)
{
	EKI *ptr;
	
	if(*top == NULL) { /* �ŏ��̂P���� */
		*top = sell;
		sell->next = NULL;
		sell->prev = NULL;
	} else {
		/* �V�K�f�[�^���ǂ��ɂȂ���΂悢�������肷�鏈�� */
		ptr = *top;
		while(ptr->next != NULL && ptr->no < sell->no) {
			ptr = ptr->next;
		}
		
		if(ptr->no < sell->no) { /* ���X�g�̍Ō���ɑ}�� */
			ptr->next = sell;
			sell->next = NULL;
			sell->prev = ptr;
		} else if(ptr != *top) { /* ���X�g�̓r���ɑ}�� */
			sell->prev = ptr->prev;
			ptr->prev->next = sell;
			ptr->prev = sell;
			sell->next = ptr;
		} else { /* ���X�g�̐擪�ɑ}�� */
			sell->next = *top;
			*top = sell;
			sell->prev = NULL;
			ptr->prev = sell;
		}
	}
}