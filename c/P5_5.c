/*P5_5.c*/

#include<stdio.h>

int main(){

	int a,b,c;
	
	printf("a‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢¨");
	scanf("%d",&a);
	printf("b‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢¨");
	scanf("%d",&b);
	
	c=a;
	a=b;
	b=c;
	
	printf("a‚Í%d,b‚Í%d\n",a,b);
	
	return 0;
		
}