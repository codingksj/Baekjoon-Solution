#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int main() {
	int TC;
	int last, pos;
	int a, b;
	int table_cond1[4] = {
		1,5,6,10
	};
	int table_cond2[4][4] = {
		{6,2,4,8},
		{1,3,9,7},
		{1,7,9,3},
		{6,8,4,2}
	};
	int table_cond3[2][2] = {
		{6,4},
		{1,9}
	};
	int index[10];
	index[1] = index[2] = index[4] = 0;
	index[3] = index[5] = index[9] = 1;
	index[6] = index[7] = 2;
	index[0] = index[8] = 3;

	bool cond1, cond2, cond3;

	scanf("%d", &TC);
	while (TC--) {
		scanf("%d %d", &a, &b);
		a %= 10;
		cond1 = a == 1 || a == 5 || a == 6 || a == 0;
		cond2 = a == 2 || a == 3 || a == 7 || a == 8;
		cond3 = a == 4 || a == 9;
		pos = index[a];
		if (cond1) {
			last = table_cond1[pos];
		}
		else if (cond2) {
			last = table_cond2[pos][b % 4];
		}
		else if (cond3) {
			last = table_cond3[pos][b % 2];
		}
		printf("%d\n", last);
		
	}
	return 0;
}