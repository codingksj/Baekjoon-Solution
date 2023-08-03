#include<stdio.h>
int main() {
	int H, W, N;
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d %d", &H, &W, &N);
		if (N % H == 0) {
			printf("%d%02d\n", H, N / H);
		}
		else {
			printf("%d%02d\n", N % H, N / H + 1);
		}
	}
	return 0;
}