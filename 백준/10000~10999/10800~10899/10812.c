#include<stdio.h>
#include<string.h>
int main() {
	int N, M;
	int S, E, mid;
	int index, idx, idx2;
	int left, right;
	int basket[101];
	int temp[101];
	int a = 1;

	//바구니 채우기
	while (a < 101) {
		basket[a] = a;
		temp[a] = a;
		a++;
	}

	scanf("%d %d", &N, &M);
	for (index = 0; index < M; index++) {
		

		scanf("%d %d %d", &S, &E, &mid);
		if (mid == S) {
			continue;
		}
		//구현
		for (idx = 0;; idx++) {
			if (mid + idx > E) break;
			temp[S + idx] = basket[mid + idx];
		}
		for (idx = S; idx < mid; idx++) {
			temp[idx+(E-mid)+1] = basket[idx];
		}
		
		for (idx = 1; idx <= N; idx++) {
			basket[idx] = temp[idx];
			
		}
		
	}
	for (idx = 1; idx <= N; idx++) {
		printf("%d ", basket[idx]);
	}
	return 0;
}