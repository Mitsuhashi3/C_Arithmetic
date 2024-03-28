/*P5_11*/

#include<stdio.h>

int main(){

	int a,b,c;
	
	printf("A‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢¨");
	scanf("%d",&a);
	printf("B‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢¨");
	scanf("%d",&b);
	printf("C‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢¨");
	scanf("%d",&c);	
	
	if(a>b){
		if(a>c){
			printf("A‚ª‘å‚«‚¢");
		}
		else
			if(a<c){
				printf("C‚ª‘å‚«‚¢");
			}
			else
				printf("A‚ÆC‚ª‘å‚«‚¢");
	}
	else
		if(a<b){
			if(b>c){
				printf("B‚ª‘å‚«‚¢");
			}
			else
				if(b<c){
					printf("C‚ª‘å‚«‚¢");
				}
				else
					printf("B‚ÆC‚ª‘å‚«‚¢");
		}
		else
			if(a>c){
				printf("A‚ÆB‚ª‘å‚«‚¢");
			}
			else
				if(a<c){
					printf("C‚ª‘å‚«‚¢");
				}
				else
					printf("‚·‚×‚Ä“¯‚¶");
	return 0;				
}
