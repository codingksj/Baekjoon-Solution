#include<stdio.h>
int main(){
	int N;
	int blank;
	scanf("%d",&N);
	blank = N-1;
	for(int i=1;i<=N;i++){
		for(int j=0;j<blank;j++){
			printf(" ");
		}
		for(int j=0;j<2*i-1;j++){
			printf("*");
		}
		printf("\n");
		blank--;
	}
    return 0;
}