#include<stdio.h>

int main() {
	int n1, n2;
	int hundred, ten, one;
	
	scanf("%d", &n1);
	scanf("%d", &n2);

	hundred = n2 / 100;
	ten = (n2 / 10) % 10;
	one = n2 % 10;
	
	printf("%d\n", one * n1);
	printf("%d\n", ten * n1);
	printf("%d\n", hundred * n1);
	printf("%d\n", n2 * n1);

	return 0;
}