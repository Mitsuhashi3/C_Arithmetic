/* pointer_1.c */
/* �����^�ϐ��ւ̃|�C���^ */
/* �|�C���^�ϐ��́A�ϐ��̃A�h���X�������ϐ�
   �g�p����ɂ́A���̉��Z�q��g�ݍ��킹�Ďg���B
   & �̓A�h���X�����o�����Z�q
   * �̓|�C���^�ϐ��̎����A�h���X�̓��e�l���������Z�q
*/

#include<stdio.h>

int main(void)
{
	int a, b, ans;
	int *ptr1;	/* int * �Ȃ̂� �����^�ւ̃|�C���^�ϐ� */
	
	a = 10;
	b = 20;
	ans = a + b;
	printf("ans�̓��e = %d\n", ans);
	
	ptr1 = &a;		/* �����^�ւ̃|�C���^�ϐ� ptr1 �� �ϐ�a �̃A�h���X���� */
	b    = *ptr1;	/* �ϐ�b �� �ϐ�a�̓��e�ł��� 10���������� */
	ans  = a + b;
	printf("ans�̓��e = %d\n", ans);
	
	*ptr1 = 100;
	ans = a + b;
	printf("ans�̓��e = %d\n", ans);
	
	ptr1  = &b;
	*ptr1 = 200;
	ans   = a + b;
	printf("ans�̓��e = %d\n", ans);/*�Ȃ�300?*
	
	return 0;
}
   