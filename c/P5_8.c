/*P5_8.c*/

#include<stdio.h>

int main(){

	int a,b;
	
	printf("値1を入力してください→");
	scanf("%d",&a);
	printf("値2を入力してください→");
	scanf("%d",&b);
	
	if(a>b){
		printf("%d",a);
	}
	else
		printf("%d",b);
	
}