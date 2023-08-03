#include<stdio.h>

int main() {
	int hour, min, sec;
	int cook_sec;
	int time = 0;

	scanf("%d %d %d", &hour, &min, &sec);
	scanf("%d", &cook_sec);

	time = 3600 * hour + 60 * min + sec + cook_sec;

	hour = (time / 3600) % 24;
	min = (time % 3600) / 60;
	sec = (time % 3600) % 60;

	printf("%d %d %d", hour, min, sec);
	return 0;
}