/* ���������X�g�̏����v���O���� eki05_lst_func.c ��
   �󃊃X�g����ł���悤�ɉ���
   
   ���o�͌`���́A�N�_�ƂȂ�w����P�T��
   ���N�_�ƂȂ�w�̔ԍ��Əo�͕���(���v���A�����v���)��
   �p�����[�^�Ƃ��ē��͂��A�w��ʂ�ɏo��
*/

/* eki06_lst_fnc.c */
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
	
	/* �������ł��ׂĂȂ��I������ŁA�󃊃X�g�ɂ��邽�߂�
	   �[�̈ʒu�Ńf�[�^�ǂ������Ȃ� */
	   
	list_ringchain(top);
	
	list_print(top);
	
	fclose(fp);
	
	return 0;
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
	int cmd; /* 1:���� / 2:�~�� */
	int beg; /* �J�n�ʒu */
	
	printf("�o�͊J�n�w�����(1�`19) -> ");
	scanf("%d", &beg);
	
	while(beg < 1 || beg > 19) {
		printf("���͂��ꂽ���l�͊Ԉ���Ă��܂��B\n\n");
		printf("�o�͊J�n�w�����(1�`19) -> ");
		scanf("%d", &beg);
	}
	
	printf("�R�}���h���� (1�͏���, 2�͍~��) -> ");
	scanf("%d", &cmd);
	
	while(cmd != ASC && cmd != DESC) {
		printf("���͂��ꂽ�R�}���h�͊Ԉ���Ă��܂��B\n\n");
		printf("�R�}���h���� (1�͏���, 2�͍~��) -> ");
		scanf("%d", &cmd);
	}
	
	if(top != NULL) {
		for(ptr = top; ptr->no != beg; ptr = ptr->next);
		
		if(cmd == ASC) {
			printf("\n%s����w���X�g(����)\n\n", ptr->name);
			
			do {
				printf("%2d, %s\n", ptr->no, ptr->name);
				ptr = ptr->next;
			} while(ptr->no != beg);
		} else if(cmd == DESC) {
			printf("\n%s����w���X�g(�~��)\n\n", ptr->name);
			
			do {
				printf("%2d, %s\n", ptr->no, ptr->name);
				ptr = ptr->prev;
			} while(ptr->no != beg);
		}
	} else {
		printf("�w���X�g�����݂��܂���\n");
	}
}