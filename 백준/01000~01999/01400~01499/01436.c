#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

int main() {
	int i, n;
	int devil_count = 0;
	int devil_num = 0;
	char s[12];
	scanf("%d", &n);

	for (i = 666; i < 10000000; i++) {
		sprintf(s, "%d", i);
		if (strstr(s, "666") != NULL) {
			devil_count++;
		}
		if (devil_count == n) {
			devil_num = i;
			break;
		}
	}
	
	printf("%d", devil_num);

	return 0;
}