/*P7_1.c*/

#include<stdio.h>

int main(){

	int jogen,cnt,sum;
	
	printf("�l����͂��Ă���������");
	scanf("%d",&jogen);
	
	sum=0;
	cnt=1;
	
	for(cnt=1;cnt<=jogen;cnt++){
		sum=sum+cnt;

	}
	printf("���v��%d",sum);

	return 0;
}