/*P7_2.c*/

#include<stdio.h>

int main(){

	int kagen,jogen,sum;
	
	printf("�l����͂��Ă���������");
	scanf("%d",&jogen);
	printf("�l����͂��Ă���������");
	scanf("%d",&jogen);

	
	sum=0;
	
	for(cnt=1;cnt<=jogen;cnt++){
		sum=sum+cnt;

	}
	printf("���v��%d",sum);

	return 0;
}