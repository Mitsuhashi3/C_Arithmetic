/*P5_5.c*/

#include<stdio.h>

int main(){

	int a,b,c;
	
	printf("a����͂��Ă���������");
	scanf("%d",&a);
	printf("b����͂��Ă���������");
	scanf("%d",&b);
	
	c=a;
	a=b;
	b=c;
	
	printf("a��%d,b��%d\n",a,b);
	
	return 0;
		
}