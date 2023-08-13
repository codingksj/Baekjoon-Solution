#include <stdio.h>

int N, M;

int res[10];
int visit[10];

void ShowRes()
{
	for (int i = 0; i < M; i++) printf("%d ", res[i]);
	printf("\n");
}

void DFS(int depth, int c)
{
	if (depth == M) ShowRes();
	for (int i = 1; i <= N; i++)
	{
		if (visit[i] == 0 && c < i)
		{
			res[depth] = i;
			visit[i] = 1;
			DFS(depth + 1, i);
			visit[i] = 0;
		}
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);

	DFS(0,0);

	return 0;
}