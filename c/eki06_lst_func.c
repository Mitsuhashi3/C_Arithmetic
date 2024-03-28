/* �����������X�g 
eki06_lst_func.c 
*/
/* ���̓t�@�C�� : eki_rnd.csv, eki_srt.csv, eki_null.csv */

#include <stdio.h>
#include <stdlib.h>

#define R_TURN
#define L_TURN

typedef struct list {
	int no;
	char name[31];
	struct list *prev;	/* �O�f�[�^�ւ̃|�C���^ */
	struct list *next;	/* ���̃f�[�^�ւ̃|�C���^ */
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
	
	/* ���͗p�t�@�C���̃I�[�v�� */
	fp = fopen(f_name1, "r"); /* f_name �Ŏ������t�@�C�������[�h���[�h�ŃI�[�v��  [r] �͓ǂݎ��*/
	if(fp == NULL){			 /* �I�[�v���ł��Ă��Ȃ��ꍇ�Afp��NULL���Ԃ���Ă��� */
		printf("�I�[�v���G���[\n");
		return -1;
	}
}

void list_insert(EKI **top, EKI *sell)
{
	EKI *ptr;
	
	if(*top == NULL){       /* ���X�g�̍ŏ���1���ڂ̓o�^ */
		*top = sell;
		sell->next = NULL;
		sell->prev = NULL;
	}else{
		/* �V�K�f�[�^���ǂ��ɂȂ��΂悢�������肷�鏈�� 
			���肷�邽�߂�ptr�ϐ������p������̃��X�g�̐擪����
			�L�[�l(����͉w�ԍ�)���r���Ă��� */
		ptr = *top;
		while(ptr->next != NULL && ptr->no < sell->no){
			ptr = ptr->next;
		}
		if(ptr->no < sell->no){ /* ���X�g�̍Ō���ɑ}�� */
			ptr->next = sell;
			sell->next = NULL;
			sell->prev = ptr;
		}else if(ptr != *top){	/* ���X�g�̓r���ɑ}�� */
			sell->prev = ptr->prev;
			sell->next = ptr;
			ptr->prev->next = sell;
			ptr->ptr = sell;
		}else{					/* ���X�g�̐擪�ɑ}�� */
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
	
	/* ptr�𗼕������X�g�̍ŏI�f�[�^�܂Ői�߂� */
	for(ptr = top; ptr->next != NULL; ptr = ptr->next);
	
	top->prev = ptr;
	ptr->next = top;
}


void list_print(EKI *top)
{
	EKI *ptr;
	int mode, beg;
	
	printf("�o�͊J�n�w�̔ԍ����w�肵�Ă��������B(1�`19) ��");
	scanf("%d", &beg);
	
	while(beg < 1 || beg > 19){
		printf("1�`19����͂��Ă�������\n");
		printf("�o�͊J�n�w�̔ԍ����w�肵�Ă��������B(1�`19)\n");
		scanf("%d", &beg);
	}
	
	printf("�o�͏����w�肵�Ă��������B(���v����=1, �����v���=2) ��");
	scanf("%d", &mode);	
	while(mode != R_TURN && mode != L_TURN){
		printf("1��2����͂��Ă�������\n");
		printf("�o�͏����w�肵�Ă��������B(���v����=1,�����v���=2) ��");
		scanf("%d", &mode);
	}
	
	/* �w��̉w�ԍ��܂�ptr��i�߂� */
	if(top != NULL){
		for(ptr = top; ptr->no != beg; ptr = ptr->next);
	
		if(mode == R_TURN){
			printf("%s���玞�v���� �w���X�g\n", ptr->name);
		
			do{
				printf("%2d, %s\n", ptr->no, ptr->name);
				ptr = ptr->next;
			}while(ptr->no != beg);
		}else{
			printf("%s���甽���v���� �w���X�g\n", ptr->name);
			do{
				printf("%2d, %s\n", ptr->no, ptr->name);
				ptr = ptr->prev;
			}while(ptr->no != beg);
		}
	}else{
		printf("�w���X�g�����݂��܂���!!\n");
	}
	
}