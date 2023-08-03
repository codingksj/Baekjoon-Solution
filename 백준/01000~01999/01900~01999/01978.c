#include<stdio.h>
#include<math.h>

int IsPrime(int N) {
	int check = 1;
	if (N <= 1)
		return 0;
	else
		for (int i = 2; i < sqrt(N) + 1; i++) {
			if (N % i == 0 && i!=N)
				check = 0;
		}
	return check;
}

int main() {
	int arr[101];
	int N;
	int sum = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		sum += IsPrime(arr[i]);
	}

	printf("%d", sum);
	return 0;
}