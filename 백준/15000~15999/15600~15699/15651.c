#include <stdio.h>

#define MAX_DEPTH 8
int N, M, result[MAX_DEPTH];
bool visited[MAX_DEPTH];

void DFS(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; ++i) {
            printf("%d ", result[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= N; i++) {
        result[depth] = i;
        DFS(depth + 1);
        result[depth] = 0;
    }
}

int main() {
    scanf("%d %d", &N, &M);
    DFS(0);
}