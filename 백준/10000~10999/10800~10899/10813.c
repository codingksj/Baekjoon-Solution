#include<stdio.h>
int main() {
	int N, M;
	int a = 0;
	int i, j;
	int index;
	int tmp;
	int arr[101];

	while (a < 101) {
		arr[a] = a;
		a++;
	}
	scanf("%d %d",&N, &M);
	for (index = 0; index < M;index++) {
		scanf("%d %d", &i, &j);
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
	for (index = 1; index <= N; index++) {
		printf("%d ", arr[index]);
	}
	return 0;
}