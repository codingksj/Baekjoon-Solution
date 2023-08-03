#include<stdio.h>
#include<iostream>

using namespace std;
int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	a > b ? printf(">") : a == b ? printf("==") : printf("<");
	return 0;
}