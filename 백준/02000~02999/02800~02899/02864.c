#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void ConvertAtoB(int A, int B, int* n, char s[]) {
	int i;
	char ConvertN[8];
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == A) {
			ConvertN[i] = B;
		}
		else {
			ConvertN[i] = s[i];
		}
	}
	ConvertN[i] = '\0';
	*n = atoi(ConvertN);
}


int main() {
	char A[8], B[8];
	int max, min;
	int maxA = 0, maxB = 0;
	int minA = 0, minB = 0;
	scanf("%s %s", A, B);
	ConvertAtoB('6', '5', &minA, A);
	ConvertAtoB('6', '5', &minB, B);
	ConvertAtoB('5', '6', &maxA, A);
	ConvertAtoB('5', '6', &maxB, B);
	min = minA + minB;
	max = maxA + maxB;
	printf("%d %d\n", min, max);
	return 0;
}