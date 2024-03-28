/* �w���t�@�C��(19�w��)��ǂݍ���ŁA�Е������X�Ƃ���
   �A�����A���X�g�̐擪����o�͂���
   (�o�͓͂ǂݍ��ݏ��̂܂�) */
/* eki03.c */
 
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

int main(void)
{
	FILE *fp;
	char *f_name1 = "eki_rnd.csv";
	char *f_name2 = "eki_srt.csv";
	char *f_name3 = "eki_null.csv";
	EKI *top, *ptr, *sell;
	int sts;
	
	
	/* ���͗p�t�@�C���̃I�[�v�� */
	fp = fopen(f_name1, "r"); /* f_name �Ŏ������t�@�C�������[�h���[�h�ŃI�[�v��  [r] �͓ǂݎ��*/
	if(fp == NULL){			 /* �I�[�v���ł��Ă��Ȃ��ꍇ�Afp��NULL���Ԃ���Ă��� */
		printf("�I�[�v���G���[\n");
		return -1;
	}

	/* ���X�g���Ȃ��Ȃ���f�[�^�ǂݍ��� */
		top = NULL;
		sell = (EKI *)malloc(sizeof(EKI));
		sts = fscanf(fp, "%d,%s", &sell->no, sell->name);
		if(sts != EOF){
			top = ptr = sell;
		}
		while(sts != EOF){
			sell = (EKI *)malloc(sizeof(EKI));
			sts = fscanf(fp, "%d, %s", &sell->no, sell->name);
			if(sts != EOF){
				ptr->next = sell;
				ptr = ptr->next;
			}else{
				ptr->next = NULL;
			}
		}
		
		/* ���X�g�̐擪����o�� */
		printf("�w���X�g\n");
		for(ptr = top; ptr != NULL; ptr = ptr->next){
			printf("%2d,%s\n", ptr->no, ptr->name);
		}
		
	return 0;
}


/* main�֐��Ŏg���A�\���̂ւ̃|�C���^�ϐ�
   top �� ���X�g�̐擪
   ptr �� ���X�g�̑���ʒu
   sell�� �V�K�f�[�^�̗̈�
*/

/* malloc�֐��́A�w��T�C�Y���̃������̈���m�ۂ�
   �m�ۂ����̈�̃A�h���X��Ԃ��֐��B
   �v���O�������̕\���ł� �� sell = (EKI *)malloc(sizeof(EKI))
   �w�\���̂̃T�C�Y��(sizeof(EKI))�̗̈���m�ۂ��A�߂�l�̃A�h���X��
   �w�\���̂ւ̃|�C���^�ɃL���X�g(EKI *)���Ă���B
*/

/* -> �� �A���[���Z�q�Ƃ����A�\���̂ւ̃|�C���^�ϐ�����A
   �\���̂̃����o�ϐ����������߂̍\���̑����p�̉��Z�q
*/

/* ������ ���X�g�\���Ŏ��̃f�[�^�ɐi�ވӖ��̋L�q�� ptr = ptr->next ������
   ptr�ϐ����g�ɁA�����������Ă���f�[�^��next�̒l����
*/