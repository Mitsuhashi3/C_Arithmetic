/* �w���t�@�C����ǂݍ���ŏ��ɕ\�� */
/* eki01.c */

#include<stdio.h>

/* �w�f�[�^��1�����ǂݍ��ނ��߂� �\���� EKI �̐錾 */
typedef struct{
	int no;			/* ���� */
	char name[31];	/* ���� */
} EKI;

int main(void)
{
	FILE *fp; /* �t�@�C������ϐ� */
	char *f_name = "eki_srt.csv"; /* ���t�@�C�����͑��̂��̂ɂ��ύX���Ď��� */
	EKI data; /* �\����EKI�^�̕ϐ�data�̐錾 */
	int sts;  /* �t�@�C���ǂݍ��݃X�e�[�^�X�p�ϐ� */
	
	fp = fopen(f_name, "r"); /* f_name �Ŏ������t�@�C�������[�h���[�h�ŃI�[�v��  [r] �͓ǂݎ��*/
	if(fp == NULL){			 /* �I�[�v���ł��Ă��Ȃ��ꍇ�Afp��NULL���Ԃ���Ă��� */
		printf("�I�[�v���G���[\n");
		return -1;
	}
	
	
	/* �t�@�C�����e��ǂݍ���ŕ\�����鏈�� */
	sts = fscanf(fp, "%d,%s", &data.no, data.name);
	while(sts != EOF){
		printf("%2d, %s\n", data.no, data.name);		
		sts = fscanf(fp, "%d,%s", &data.no, data.name);

	}
	
	
	fclose(fp);
	return 0;
}