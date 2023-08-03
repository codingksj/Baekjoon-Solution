#include<stdio.h>

int main() {
	int L=-1, P=-1 ,V=-1; 
	int index = 1, period = 0, R = 0, ans = 0;
	while (1) {
		scanf("%d %d %d", &L, &P, &V);
		if (((L == 0) && (P == 0) && (V == 0)))
			break;
		R = (V % P);
		period = (V - R) / P;
		if (R > L)
			R = L;
		ans = period * L + R;
		printf("Case %d: %d\n", index, ans);
		index++;
	}
	
	return 0;
}