#include<stdio.h>
#include<stdlib.h>
int main(){
	int N;
	int count = 0;
	scanf("%d", &N);
	while (1) {
		if (N % 5 == 0) {
			count += N / 5;
			break;
		}
		N -= 3;
		count++;
		if (N <= 0)
			break;
	}
	if (N < 0)
		printf("-1\n");
	else
		printf("%d\n", count);
	return 0;
}