/*P5_5.c*/

#include<stdio.h>

int main(){

	int a,b,c;
	
	printf("aを入力してください→");
	scanf("%d",&a);
	printf("bを入力してください→");
	scanf("%d",&b);
	
	c=a;
	a=b;
	b=c;
	
	printf("aは%d,bは%d\n",a,b);
	
	return 0;
		
}