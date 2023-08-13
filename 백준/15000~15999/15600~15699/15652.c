#include<stdio.h>
#include<stdbool.h>

#define MAX_DEPTH 9

int N, M, result[MAX_DEPTH];
bool visited[MAX_DEPTH];

void DFS(int depth, int num) {
    if (depth == M) {
        for (int i = 0; i < M; ++i) {
            printf("%d ", result[i]);
        }
        printf("\n");
        return;
    }
    for (int i = num; i <= N; i++) {
        visited[i] = true;
        result[depth] = i;
        DFS(depth + 1, i);
        visited[i] = false;
    }
}

int main() {
    scanf("%d %d", &N, &M);
    DFS(0,1);
}