/*P5_11*/

#include<stdio.h>

int main(){

	int a,b,c;
	
	printf("Aを入力してください→");
	scanf("%d",&a);
	printf("Bを入力してください→");
	scanf("%d",&b);
	printf("Cを入力してください→");
	scanf("%d",&c);	
	
	if(a>b){
		if(a>c){
			printf("Aが大きい");
		}
		else
			if(a<c){
				printf("Cが大きい");
			}
			else
				printf("AとCが大きい");
	}
	else
		if(a<b){
			if(b>c){
				printf("Bが大きい");
			}
			else
				if(b<c){
					printf("Cが大きい");
				}
				else
					printf("BとCが大きい");
		}
		else
			if(a>c){
				printf("AとBが大きい");
			}
			else
				if(a<c){
					printf("Cが大きい");
				}
				else
					printf("すべて同じ");
	return 0;				
}
