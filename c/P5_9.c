/*P5_8.c*/

#include<stdio.h>

int main(){

	int a,b,c;
	
	printf("A����͂��Ă���������");
	scanf("%d",&a);
	printf("B����͂��Ă���������");
	scanf("%d",&b);
	printf("C����͂��Ă���������");
	scanf("%d",&c);
	
	if(a>b){
		if(a>c){
			printf("A�̒l��%d",a);			
		}
		else
			printf("C�̒l��%d",c);			
	}
	else
		if(b>c){
			printf("B�̒l��%d",b);
		}
		else
			printf("C�̒l��%d",c);
	
	return 0;
}