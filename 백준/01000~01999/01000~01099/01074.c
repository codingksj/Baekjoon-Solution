#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<memory.h>
#include<math.h>

int N, R, C;
int answer;

void Z(int y, int x, int size) {
	if (y == R && x == C) {
		printf("%d\n", answer);
		return;
	}
	bool yExist = R < y + size && R >= y;
	bool xExist = C < x + size && C >= x;
	if (yExist && xExist) {
		Z(y, x, size / 2);
		Z(y, x + size / 2, size / 2);
		Z(y + size / 2, x, size / 2);
		Z(y + size / 2, x + size / 2, size / 2);
	}
	else {
		answer += size * size;
	}
}

int main() {
	scanf("%d %d %d", &N, &R, &C);
	Z(0, 0, (1 << N));
	return 0;
}