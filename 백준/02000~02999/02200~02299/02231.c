#include<stdio.h>

int main() {
	int arr[7] = {0};
	int num, n;
	int generator = 0;
	int check = 0;
	int index = 0;

	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		check = i;
		index = 0;
		n = i;
		while (n > 0) {
			arr[index] = n % 10;
			n /= 10;
			check += arr[index];
			index += 1;
		}
		if (check == num) {
			generator = i;
			break;
		}
	}
	printf("%d", generator);
	return 0;
}