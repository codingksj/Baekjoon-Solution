#include<stdio.h>

int Square(int n) {
	return n * n;
}

int main() {
	int n[5] = { 0 };
	int num = 0;
	scanf("%d %d %d %d %d", &n[0], &n[1], &n[2], &n[3], &n[4]);
	for (int i = 0; i < 5; i++) {
		num += Square(n[i]);
	}
	printf("%d", num%10);

	return 0;
}