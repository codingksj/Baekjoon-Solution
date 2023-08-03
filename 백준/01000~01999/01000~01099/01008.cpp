#include<stdio.h>
#include<algorithm>
#include<iostream>

using namespace std;
int main() {
	double a = 0, b = 0;
	scanf("%lf %lf", &a, &b);
	printf("%.12lf", a / b);
	return 0;
}