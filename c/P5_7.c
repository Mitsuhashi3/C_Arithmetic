/*P5_7.c*/

#include<stdio.h>

int main(){

	int a;
	printf("値を入力してください→");
	scanf("%d",&a);
	
	if(a>=70){
		printf("合格",a);
	}
	else
		printf("不合格",a);
	return 0;	
	
}