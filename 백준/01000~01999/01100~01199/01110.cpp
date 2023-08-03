#include<stdio.h>
#include<iostream>

using namespace std;
int main() {
	int n = 0, original_n, ten = 0, one = 0, count = 1;
	scanf("%d", &n);
	original_n = n;
	while (true) {
		if (n >= 10) {
			ten = n / 10;
			one = n % 10;
		}
		else {
			ten = 0;
			one = n;
		}
		n = one*10 + ((ten + one)%10);
		if (n == original_n) {
			break;
		}
		count++;

	}
	printf("%d", count);
	return 0;
}