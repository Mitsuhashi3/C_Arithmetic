/* �w���t�@�C��(19�w��)��ǂݍ���ŁA�Е������X�Ƃ���
   �A�����A���X�g�̐擪����o�͂���
   ���f�[�^���ǂ̂悤�ȏ��ł��A�w�ԍ����Ƀ��X�g���Ȃ�!!
   ���\�[�g�A���S���Y�����g���킯�ł͂Ȃ� */
/* eki04_lst.c */
/* ���̓t�@�C�� : eki_rnd.csv, eki_srt.csv, eki_null.csv */

#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int no;
	char name[31];
	struct list *next;
} EKI;


int main(void)
{
	FILE *fp;
	char *f_name1 = "eki_rnd.csv";
	char *f_name2 = "eki_srt.csv";
	char *f_name3 = "eki_null.csv";
	EKI *top, *sell, *ptr, *ins_pt;
	int sts;
	
	/* ���͗p�t�@�C���̃I�[�v�� */
	fp = fopen(f_name1, "r");

	top = NULL;
	sell = (EKI *)malloc(sizeof(EKI));
	sts = fscanf(fp, "%d,%s", &sell->no, sell->name);

	while (sts != EOF) {
		
		/* ���X�g�̓K�؂Ȉʒu��sell�Ŏ������V�K�f�[�^��A�����鏈��(�n�܂�) */
		
		if(top == NULL){       /* ���X�g�̍ŏ���1���ڂ̓o�^ */
			top = sell;
			sell->next = NULL;
		}else{
			/* �V�K�f�[�^���ǂ��ɂȂ��΂悢�������肷�鏈�� 
				���肷�邽�߂�ptr�ϐ������p������̃��X�g�̐擪����
				�L�[�l(����͉w�ԍ�)���r���Ă��� */
			ptr = top;
			while(ptr->next != NULL && ptr->no < sell -> no){
				ins_pt = ptr;	/* ins_pt��ptr�������ւ�����O��ێ� */
				ptr = ptr->next;
			}
			if(ptr->no < sell->no){ /* ���X�g�̍Ō�����ɑ}�� */
				ptr->next = sell;
				sell->next = NULL;
			}else if(ptr != top){	/* ���X�g�̓r���ɑ}�� */
				ins_pt->next = sell;
				sell->next = ptr;
			}else{					/* ���X�g�̐擪�ɑ}�� */
				sell->next = top;
				top = sell;
			}
			
		}

		/* ���X�g�̓K�؂Ȉʒu��sell�Ŏ������V�K�f�[�^��A�����鏈��(�I���) */
		
		sell = (EKI *)malloc(sizeof(EKI));
		sts = fscanf(fp, "%d,%s", &sell->no, sell->name);
	}
	
	/* ���X�g�̐擪����Ō�̃f�[�^�܂ŘA���o�͂��鏈�� */
	/* ���X�g�̐擪����o�� */
	printf("�w���X�g\n");
	for(ptr = top; ptr != NULL; ptr = ptr->next){
		printf("%2d,%s\n", ptr->no, ptr->name);
	}
			
	
	fclose(fp);

	return 0;
}



/*
���X�g�̑}���ʒu�̔���

top��NULL�̂Ƃ��́u�ŏ���1���ځv
top�������ԍ���菬�����Ƃ��́u�V���Ȑ擪�ɂȂ�v

���X�g�̓r������Ō���ɓo�^�����P�[�X�ł́A
���X�g�̐擪����ptr�ϐ��̎����ʒu���}���f�[�^�̔ԍ���
�傫���Ȃ�ʒu�܂�ptr�ϐ����ړ������A
�Eptr->next��NULL�̈ʒu�܂ŗ��Ă��A�}���f�[�^�̔ԍ���
  �傫���Ƃ��́A�u�Ō���v
�Eptr->next��NULL�ł͂Ȃ��Ƃ��́Aptr�̎���1�O�A�܂�u�r���v

ptr -> next ->next = NULL:

*/