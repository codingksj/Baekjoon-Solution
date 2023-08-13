#include <stdio.h>

#define MAX_DEPTH 10
int N, M;

int permutation[MAX_DEPTH];
int visit[MAX_DEPTH];
int numbers[MAX_DEPTH];

void InsertionSort(int arr[MAX_DEPTH]);
void Swap(int* a, int* b);
void DFS(int depth);

int main(void)
{
	int i;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		scanf("%d", &numbers[i]);
	}
	InsertionSort(numbers);
	DFS(0);

	return 0;
}

void InsertionSort(int arr[MAX_DEPTH]) {
	int i, j;
	for (i = 0; i < N - 1; i++) {
		j = i;
		while (j >= 0 && arr[j] > arr[j + 1]) {
			Swap(&arr[j], &arr[j + 1]);
			j--;
		}
	}
}

void Swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
};

void DFS(int depth)
{
	if (depth == M) {
		for (int i = 0; i < M; i++) printf("%d ", permutation[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		if (visit[i] == 1) continue;
		permutation[depth] = numbers[i-1];
		visit[i] = 1;
		DFS(depth + 1);
		visit[i] = 0;
	}
}