/*P5_10.c*/

#include<stdio.h>

int main(){

	int a,b;

	printf("A����͂��Ă���������");
	scanf("%d",&a);
	printf("B����͂��Ă���������");
	scanf("%d",&b);


	if(a==b){
		printf("������");
	}
	else
		if(a>b){
			printf("A���傫��");
		}
		else
			printf("B���傫��");
			
	return 0;
}