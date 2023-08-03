#include<stdio.h>

int main() {
	int num;
	int n = 1;
	int k = 0;

	scanf("%d", &num);
	while (1) {
		n += 6 * k;
		if (num <= n) {
			break;
		}

		k++;
	}
	
	printf("%d", k+1);
	return 0;
}