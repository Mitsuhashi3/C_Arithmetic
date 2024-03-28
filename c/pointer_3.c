/* pointer_3.c */
/* �|�C���^�ϐ������p���Amain���Œ�`�����������
   �Ăяo���Đ�ŏo�� */
   
#include<stdio.h>




void st_out(char *);						/* �������擪����Ō�܂�1�������o�� */
void ch_out(char *, int);					/* �������n�Ԗڂ̕�����1���������o�� */
void stpt_out(char *, int, int);			/* ������̎w��ʒu����n��������ʂ̗̈�ɃR�s�[ */
void stpt_cpy(char *, char *, int, int);	/* ������̎w��ʒu����n��������ʗ̈�ɃR�s�[ */
	
int main(void)
{
	char *str1 = "abcdefghijklmnopqrstuvwxy"; /* 26����+Null('\n')������27�o�C�g�̗̈� */
	char str2[11]; /* ������̕������R�s�[�̊i�[��(�ő�10����) */
	
	st_out(str1);				/* str1�S�̂̏o�� */
	ch_out(str1,10);			/* str1��n�Ԗڂ̕������o�� */
	stpt_out(str1, 5, 8);		/* str1��5�Ԗڂ���8���������o�� */
	stpt_cpy(str1, str2, 10, 5);/* str1��10�Ԗڂ���5��������str2�ɃR�s�[ */
	st_out(str2);
	
	return 0;
}

void st_out(char *ptr)
{
	while (*ptr != '\0'){	/* ptr�ϐ��̎���1������	Null�����ł͂Ȃ��� */
		printf("%c", *ptr); /* ptr�ϐ��̎������1�������o�� */
		ptr++;				/* ptr�ϐ��̎������1�������o�� */
	}
	printf("\n");
	
}

void ch_out(char *ptr, int n)
{
	printf("%c\n", *(ptr + n)); /* ()��t����t���Ȃ��̉��Z�̗D�揇����!! */
}

void stpt_out(char *ptr,int n, int m)
{
	int i;
	for(i = 1; i <= m; i++){
		printf("%c", *(ptr + n));
		n++;
	}
	printf("\n");
}

void stpt_cpy(char *ptr1, char *ptr2, int n, int m)
{
	for(ptr1 += n; m > 0; m--){
		*ptr2 = *ptr1;
		ptr1 ++;
		ptr2 ++;
	}
	*ptr2 = '\0';
}