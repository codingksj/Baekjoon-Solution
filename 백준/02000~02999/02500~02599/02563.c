#include<stdio.h>
#include<string.h>
int main() {
	int paper[100][100] = { 0, };
	int x[101];
	int y[101];
	int sum = 0;
	int i, j;
	int N;
	int X, Y;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}
	for (i = 0; i < N; i++) {
		for (X = x[i]; X < x[i] + 10; X++) {
			for (Y = y[i]; Y < y[i] + 10; Y++) {
				paper[X][Y] = 1;
			}
		}
		
	}
	for (i = 0; i < 100; i++) {
		for (j = 0; j < 100; j++) {
			sum += paper[i][j];
		}
	}
	printf("%d", sum);
	
	
	return 0;
}