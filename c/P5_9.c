/*P5_8.c*/

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
			printf("Aの値→%d",a);			
		}
		else
			printf("Cの値→%d",c);			
	}
	else
		if(b>c){
			printf("Bの値→%d",b);
		}
		else
			printf("Cの値→%d",c);
	
	return 0;
}