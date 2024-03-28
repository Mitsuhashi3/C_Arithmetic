/*P5_10.c*/

#include<stdio.h>

int main(){

	int a,b;

	printf("A‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢¨");
	scanf("%d",&a);
	printf("B‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢¨");
	scanf("%d",&b);


	if(a==b){
		printf("“™‚µ‚¢");
	}
	else
		if(a>b){
			printf("A‚ª‘å‚«‚¢");
		}
		else
			printf("B‚ª‘å‚«‚¢");
			
	return 0;
}