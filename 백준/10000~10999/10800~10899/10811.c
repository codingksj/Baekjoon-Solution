#include<stdio.h>
int main() {
	int N, M;
	int n;
	int i, j;
	int index, idx;
	int tmp;
	int delta;
	int basket[101];
	
	for (index = 1; index <= 100; index++) {
		basket[index] = index;
	}
	scanf("%d %d", &N, &M);

	for (index = 0; index < M;index++) {
		scanf("%d %d", &i, &j);
		for (idx = i; idx <= (i+j)/2; idx++) {
			delta = idx - i;
			tmp = basket[j - delta];
			basket[j - delta] = basket[i + delta];
			basket[i + delta] = tmp;
			
		}
		
	}
	for (index = 1; index <= N; index++) {
		printf("%d ", basket[index]);
	}
	return 0;
}