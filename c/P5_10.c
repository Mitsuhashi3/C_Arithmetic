/*P5_10.c*/

#include<stdio.h>

int main(){

	int a,b;

	printf("Aを入力してください→");
	scanf("%d",&a);
	printf("Bを入力してください→");
	scanf("%d",&b);


	if(a==b){
		printf("等しい");
	}
	else
		if(a>b){
			printf("Aが大きい");
		}
		else
			printf("Bが大きい");
			
	return 0;
}