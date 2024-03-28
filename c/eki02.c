/* �w���t�@�C��(19�w��)��ǂݍ���ŁA
   19�w���̍\���̔z��Ɋi�[���A�w�ԍ�����
   �\�[�g���ꂽ��Ԃŏo�͂��� */
/* eki02.c */
/* 
	���̓t�@�C�� : eki_rnd.csv, eki_srt.csv 
	�o�̓t�@�C�� : eki_srtnew.csv
*/
   
#include<stdio.h>

/* �w�f�[�^��1�����ǂݍ��ނ��߂� �\���� EKI �̐錾 */
typedef struct{
	int no;			/* ���� */
	char name[31];	/* ���� */
} EKI;

int main(void)
{
	FILE *fp1, *fp2;
	char *f_name1 = "eki_rnd.csv";		/* eki_srt.csv�ł����� */
	char *f_name2 = "eki_srtnew.csv";	/*  */
	EKI data[19], tmp;	/* 19�s */
	int sts, idx, i, j;
	
	fp1 = fopen(f_name1, "r"); /* f_name �Ŏ������t�@�C�������[�h���[�h�ŃI�[�v��  [r] �͓ǂݎ��*/
	if(fp1 == NULL){			 /* �I�[�v���ł��Ă��Ȃ��ꍇ�Afp��NULL���Ԃ���Ă��� */
		printf("�I�[�v���G���[\n");
		return -1;
	}
	
	/* �\���̔z��ւ̓ǂݍ��݃��[�v */
	idx = 0;
	sts = fscanf(fp1, "%d,%s", &data[0].no, data[0].name);
	while(sts != EOF){
		idx ++;
		sts = fscanf(fp1, "%d,%s", &data[idx].no, data[idx].name);
	}
	
	/* �\���̔z����w�ԍ����L�[�Ƃ��ď����ɕ��בւ���(�}���\�[�g) */
	for(i = 1; i <= 18; i ++){
		tmp = data[i];
		j = i;
		while(j > 0 && data[j - 1].no > tmp.no){
			data[j] = data[j - 1];
			j --;
		}
		data[j] = tmp;
	}
	
	/* �o�͗p�t�@�C���̃I�[�v�� */
	fp2 = fopen(f_name2, "w");
	if(fp2 == NULL){
		printf("�I�[�v���G���[\n");
		return -1;
	}
	
	/* �\���̔z��̓��e���o�̓t�@�C���ɏ����o������ */
	for(idx = 0; idx <= 18; idx ++){
		fprintf(fp2, "%d,%s\n", data[idx].no, data[idx].name);
	}
	
	
	fclose(fp1);
	fclose(fp2);
	return 0;
	
}