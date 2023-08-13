#include <stdio.h>

int N, M;

int permutation[10];
int visit[10];

void Permutation()
{
	for (int i = 0; i < M; i++) printf("%d ", permutation[i]);
	printf("\n");
}

void DFS(int depth)
{
	if (depth == M) Permutation();
	for (int i = 1; i <= N; i++)
	{
		if (visit[i] == 1) continue;
		permutation[depth] = i;
		visit[i] = 1;
		DFS(depth + 1);
		visit[i] = 0;
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);

	DFS(0);

	return 0;
}