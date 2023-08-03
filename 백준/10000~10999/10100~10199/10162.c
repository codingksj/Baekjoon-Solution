#include<stdio.h>

int main() {
	int A = 0;
	int B = 0;
	int C = 0;
	int T = 0;
	scanf("%d", &T);
	
	A = T / 300;
	T %= 300;
	B = T / 60;
	T %= 60;
	C = T / 10;
	T %= 10;

	switch (T) {
		case 0: 
			printf("%d %d %d\n", A, B, C);
			break;
		default:
			printf("-1\n");
	}
	return 0;
}