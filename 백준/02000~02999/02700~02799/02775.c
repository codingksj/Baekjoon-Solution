#include<stdio.h>

int func(int a, int b) {
	if (a == 0)
		return b;
	else if (b == 1)
		return 1;
	return func(a, b - 1) + func(a - 1, b);
}

int main() {
	int T, a, b;

	scanf("%d", &T);
	while (T--) {
		scanf("%d", &a);
		scanf("%d", &b);
		printf("%d\n", func(a, b));
	}
	return 0;
}