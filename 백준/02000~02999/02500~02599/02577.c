#include<stdio.h>

int main() {
	int numbers[10] = { 0, };
	int n1, n2, n3;
	int result;
	scanf("%d", &n1);
	scanf("%d", &n2);
	scanf("%d", &n3);
	result = n1 * n2 * n3;
	while (result > 0) {
		numbers[result % 10]++;
		result /= 10;
	}
	for (int i = 0; i < 10; i++) {
		printf("%d\n", numbers[i]);
	}
	return 0;
}