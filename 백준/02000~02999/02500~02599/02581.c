#include<stdio.h>
#include<math.h>
int IsPrime(int n) {
	int i, max;
	if (n == 1)
		return 0;
	max = (int)sqrt(n);
	for (i = 2; i <= max; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int N, M, i;
	int sum = 0, check;
	int min = 10001;

	scanf("%d", &N);
	scanf("%d", &M);
	for (i = N; i <= M; i++) {
		check = IsPrime(i);
		if (check) {
			min = (i < min) ? i : min;
			sum += i;
		}
	}
	(sum > 0) ? printf("%d\n%d\n", sum, min) : printf("-1");
	return 0;
}