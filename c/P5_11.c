/*P5_11*/

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
			printf("A���傫��");
		}
		else
			if(a<c){
				printf("C���傫��");
			}
			else
				printf("A��C���傫��");
	}
	else
		if(a<b){
			if(b>c){
				printf("B���傫��");
			}
			else
				if(b<c){
					printf("C���傫��");
				}
				else
					printf("B��C���傫��");
		}
		else
			if(a>c){
				printf("A��B���傫��");
			}
			else
				if(a<c){
					printf("C���傫��");
				}
				else
					printf("���ׂē���");
	return 0;				
}
