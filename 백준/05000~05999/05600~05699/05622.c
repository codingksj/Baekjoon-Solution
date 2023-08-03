#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

int main() {
	int sum = 0;
	int pos;
	int weight[26] = {
		3,3,3,
		4,4,4,
		5,5,5,
		6,6,6,
		7,7,7,
		8,8,8,8,
		9,9,9,
		10,10,10,10
	};
	char tele[16];

	scanf("%s", tele);

	for (int i = 0; tele[i] != '\0'; i++) {
		pos = tele[i] - 'A';
		sum += weight[pos];
	}
	printf("%d\n", sum);

	return 0;
}