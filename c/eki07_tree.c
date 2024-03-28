/* �w���t�@�C��(19�w��)��ǂݍ���ŁA�w�ԍ������ƂɁA
   �u���̎q �� �� �� �E�̎q�v�̃��[���œo�^����
   �Q���T���؂��쐬���A�����獶�ɏ��񂵁A
   ���ԏ��Ŏ��o���u�o�C�i���\�[�g�v���s�� */

/* eki07_tree.c */
/* ���̓t�@�C�� : eki_rnd.csv, eki_srt.csv, eki_null.csv */

#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	int no;
	char name[31];
	struct tree *left;
	struct tree *right;
} EKI;

int data_entry(FILE *, EKI *);   /* ���̓t�@�C������P���ǂ� */
void tree_insert(EKI *, EKI *);  /* �؂̓����(���E���[�g)�̃A�h���X�ƁA�o�^������
                                    �f�[�^�̃A�h���X��n���ƓK�؂Ȉʒu�ɓo�^ */
void tree_print(EKI *);          /* �؂ɓo�^���ꂽ�f�[�^���w�ԍ��̏����ɏo�� */

int main(void)
{
	FILE *fp;
	char *f_name1 = "eki_rnd.csv";
	char *f_name2 = "eki_srt.csv";
	char *f_name3 = "eki_null.csv";
	EKI *root, *sell;
	int sts;
	
	/* ���͗p�t�@�C���̃I�[�v�� */
	fp = fopen(f_name1, "r");
	if (fp == NULL) {
		printf("�I�[�v���G���[\n");
		return -1;
	}
	
	root = NULL;
	sell = (EKI *)malloc(sizeof(EKI));
	sts = data_entry(fp, sell);
	
	while (sts != EOF) {
		if (root == NULL) {
			root = sell;				/* �P���ڂ̓o�^ */
		} else {
			tree_insert(root, sell);    /* �Q���ڈȍ~�̓o�^ */
		}
		sell = (EKI *)malloc(sizeof(EKI));
		sts = data_entry(fp, sell);
	}
	/* �؂ɓo�^���ꂽ�f�[�^�̏o�͏����Ăяo�� */
	printf("�w���X�g\n");
	if (root != NULL) {
		tree_print(root);   /* �o�C�i���\�[�g(���ԏ����o��)�����Ăяo�� */
	}
		
	return 0;
}

int data_entry(FILE *fp, EKI *sell)
{
	int sts;
	
	sts = fscanf(fp, "%d,%s", &sell->no, sell->name);
	sell->left = NULL;
	sell->right = NULL;
	return sts;
}

void tree_insert(EKI *ptr, EKI *sell)
{
	if (ptr->no > sell->no) {
		if (ptr->left != NULL) {            /* ���̎q�Ƃ��ēo�^�ł��邩�ł��Ȃ����̐U�蕪�� */
			tree_insert(ptr->left, sell);   /* �������؂ɐi��(�ċA�Ăяo��) */
		} else {
			ptr->left = sell;               /* ���̎q�Ƃ��ēo�^ */
		}
	} else {
		if (ptr->right != NULL) {           /* �E�̎q�Ƃ��ēo�^�ł��邩�ł��Ȃ����̐U�蕪�� */
			tree_insert(ptr->right, sell);  /* �E�����؂ɐi��(�ċA�Ăяo��) */
		} else {
			ptr->right = sell;              /* �E�̎q�Ƃ��ēo�^ */
		}
	}
}

void tree_print(EKI *ptr)
{
	if (ptr != NULL) {
		tree_print(ptr->left);
		printf("%2d, %s\n", ptr->no, ptr->name);
		tree_print(ptr->right);
	}
}