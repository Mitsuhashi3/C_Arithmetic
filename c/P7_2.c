/*P7_2.c*/

#include<stdio.h>

int main(){

	int kagen,jogen,sum;
	
	printf("値を入力してください→");
	scanf("%d",&jogen);
	printf("値を入力してください→");
	scanf("%d",&jogen);

	
	sum=0;
	
	for(cnt=1;cnt<=jogen;cnt++){
		sum=sum+cnt;

	}
	printf("合計は%d",sum);

	return 0;
}