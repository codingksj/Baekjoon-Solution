#include<stdio.h>
int count[10001];
int main() {
	int n, i, j;
	int num;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &num);
		count[num]++;
	}
	for (i = 1; i <= 10000; i++) {
		for (j = 1; j <= count[i]; j++) {
			printf("%d\n", i);
		}
	}
	return 0;
}