#include<stdio.h>
#include<string.h>
int main() {
	int N, T;
	int i;
	int q = 0, d = 0, n = 0, p = 0;

	scanf("%d", &T);

	for (i = 0; i < T; i++) {
		scanf("%d", &N);
		q = 0, d = 0, n = 0, p = 0;
		while (N != 0) {
			if (N >= 25) {
				q = N / 25;
				N -= (25 * q);
			}
			else if (N >= 10) {
				d = N / 10;
				N -= (10 * d);
			}
			else if (N >= 5) {
				n = N / 5;
				N -= (5 * n);
			}
			else {
				p = N;
				N -= p;
			}
		}
		printf("%d %d %d %d\n", q, d, n, p);
	}
	return 0;
}