/*�����񏈗��֐��̗��K str_func.c*/
/*	strlen ������̒���
	strcpy ������R�s�[
	strcat ������A��
	strcmp �������r
*/

#include<stdio.h>
#include<string.h>

int main(void)
{

	char strin[101];
	char st_wk[31];
	char st1[] = "abc";
	char st2[] = "defg";
	char st3[] = "abc";
	int nagasa;
	int jg;
	
	/*���͂���������̒����\��*/
	printf("strin���́�");
	scanf("%s",strin);
	nagasa = strlen(strin);
	printf("strin�̒��� = %d\n",nagasa);
	
	/*������̃R�s�[*/
	strcpy(st_wk,st1);	/*���̕������O�̗̈�ɃR�s�[*/
	printf("st_wk = %s\n",st_wk);
	
	/*������̘A��*/
	strcat(st_wk,st2); /*st_wk�ɑ��݂��镶�����st2�̕������A��*/
	printf("st_wk = %s\n",st_wk);	
	
	/*������̔�r*/
	/*	strcmp�֐��̖߂�l�́A0(�[��)�̎�����r����2�̕����񂪓���
		0(�[��)�ȊO�͓����łȂ������Ƃ�������*/
	if(strcmp(st1,st2)==0){
		printf("st1��st2�͓���\n");
	}else{
		printf("st1��st2�͈Ⴄ\n");	
	}
	if(strcmp(st1,st3)==0){
		printf("st1��st3�͓���\n");
	}else{
		printf("st1��st3�͈Ⴄ\n");	
	}
	
	return 0;

}