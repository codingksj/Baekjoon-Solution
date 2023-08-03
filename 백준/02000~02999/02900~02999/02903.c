#include<stdio.h>
#include<string.h>
int main() {
	int N;
	int i;
	int a = 2;

	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		a = (2 * a) - 1;
	}
	printf("%d", a * a);
	return 0;
}