/*P5_6.c*/

#include<stdio.h>

int main(){

	int a;
	printf("値を入力してください→");
	scanf("%d",&a);
	
	if(a>=100){
		printf("100以上の値は%d",a);
	}
	return 0;	
	
}