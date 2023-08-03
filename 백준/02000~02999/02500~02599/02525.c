#include<stdio.h>
int main() {
	int h,m;
	int time, cook_time;

	scanf("%d %d", &h,&m);
	scanf("%d", &cook_time);

	time = h * 60 + m + cook_time;
	h = (time / 60) % 24, m = time % 60;
	printf("%d %d", h, m);
	return 0;
}