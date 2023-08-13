#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<memory.h>
#include<math.h>

int main() {
	char s[30];
	int N;
	int i;
	int decimal;

	scanf("%d", &decimal);
	scanf("%d", &N);

	int index = 0;
	while (decimal > 0) {
		s[index++] = ((decimal % N) < 10) ? (decimal % N) + '0' : (decimal % N) - 10 + 'A';
		decimal /= N;
	}
	index--;

	for (i = index; i >= 0; i--) {
		printf("%c", s[i]);
	}
	return 0;
}