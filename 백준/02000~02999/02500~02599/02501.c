#include<stdio.h>
#include<string.h>
int main() {
	int k, i;
	int N, K;
	k = 0;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N;i++) {
		if (N % i == 0) {
			k++;
			if (k == K) {
				printf("%d", i);
				return 0;
			}
		}
	}
	printf("0");
	
	return 0;
}