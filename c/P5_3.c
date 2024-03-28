/*P5_3.c*/

#include<stdio.h>

int main(){

	int a,b,c;
	
	printf("底辺の値→");
	scanf("%d",&a);
	printf("高さの値→");
	scanf("%d",&b);
	
	c=a*b/2;
	
	printf("三角形の答えは%d",c);
	
	return 0;

}