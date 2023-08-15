#include<stdio.h>

int main() {
	long long a,b,c,d;
	long long k;
	scanf("%lld",&k);
	scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
	if ((a - c) * k == d - b) {
		printf("Yes %lld", a * k + b);
	}
	else
		printf("No");

	return 0;
}