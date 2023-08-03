#include<stdio.h>
#include<stdbool.h>
int main() {
	int year;
	bool cond1, cond2;
	scanf("%d",&year);
	cond1 = year%4==0 && year%100!=0;
	cond2 = year%400 == 0;
	(cond1 || cond2) ? printf("1") : printf("0");
	return 0;
}