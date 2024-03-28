/*P7_1.c*/

#include<stdio.h>

int main(){

	int jogen,cnt,sum;
	
	printf("’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢¨");
	scanf("%d",&jogen);
	
	sum=0;
	cnt=1;
	
	for(cnt=1;cnt<=jogen;cnt++){
		sum=sum+cnt;

	}
	printf("‡Œv‚Í%d",sum);

	return 0;
}