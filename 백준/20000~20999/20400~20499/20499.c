#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<memory.h>
#include<math.h>

int main() {
	bool cond1, cond2;
	int K, D, A;
	scanf("%d/%d/%d", &K, &D, &A);
	cond1 = (K + A) < D;
	cond2 = D == 0;
	(cond1 || cond2) ? printf("hasu") : printf("gosu");
	return 0;
}