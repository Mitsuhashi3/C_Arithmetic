/*P7_1.c*/

#include<stdio.h>

int main(){

	int jogen,cnt,sum;
	
	printf("値を入力してください→");
	scanf("%d",&jogen);
	
	sum=0;
	cnt=1;
	
	for(cnt=1;cnt<=jogen;cnt++){
		sum=sum+cnt;

	}
	printf("合計は%d",sum);

	return 0;
}