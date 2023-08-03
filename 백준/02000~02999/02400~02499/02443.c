#include<stdio.h>
int main(){
	int N;
	int blank;
	scanf("%d",&N);
	blank = 0;
	for(int i=N;i>=1;i--){
		for(int j=0;j<blank;j++){
			printf(" ");
		}
		for(int j=0;j<2*i-1;j++){
			printf("*");
		}
		printf("\n");
		blank++;
	}
    return 0;
}