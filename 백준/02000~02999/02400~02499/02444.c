#include<stdio.h>
#include<string.h>
int main() {
	int n;
	int c, r;
	int empty, star;
	scanf("%d", &n);
	empty = n;
	star = 0;
	for (r = 1; r <= 2 * n - 1; r++) {
		//1 ~ n번째 줄
		if (r >= 1 && r <= n) {
			empty--;
			star++;
			for (c = 0; c < empty; c++) {
				printf(" ");
			}
			for (c = 0; c < 2 * star - 1; c++) {
				printf("*");
			}
			printf("\n");
		}

		//n+1 ~ 2n-1번째 줄
		else {
			empty++;
			star--;
			for (c = 0; c < empty; c++) {
				printf(" ");
			}
			for (c = 0; c < 2 * star - 1; c++) {
				printf("*");
			}
			printf("\n");
		}
	}
	return 0;
}