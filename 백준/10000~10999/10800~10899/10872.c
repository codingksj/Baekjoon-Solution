#include<stdio.h>

int fact(int N) {
	if (N == 0 || N == 1)
		return 1;
	else
		return N * fact(N - 1);
}

int main() {
	int N;
	scanf("%d", &N);
	printf("%d\n", fact(N));
	return 0;
}