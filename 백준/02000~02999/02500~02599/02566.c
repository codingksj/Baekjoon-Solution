#include<stdio.h>
#include<string.h>
int main() {
	int N[10][10];
	int i, j;
	int max;
	int r, c;
	for (i = 1; i < 10; i++) {
		for (j = 1; j < 10; j++) {
			scanf("%d", &N[i][j]);
		}
	}
	max = N[1][1];
	r = 1, c = 1;
	for (i = 1; i < 10; i++) {
		for (j = 1; j < 10; j++) {
			if (max < N[i][j]) {
				max = N[i][j];
				r = i;
				c = j;
			}
		}
	}
	printf("%d\n", max);
	printf("%d %d", r, c);
	return 0;
}