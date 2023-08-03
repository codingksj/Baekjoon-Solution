#include <stdio.h>

#define SIZE 100002

int numbers[SIZE];
int sum[SIZE];
int T[SIZE];

int main() {
    int N, K;
    int i;
    int ans=-1000000000;
    scanf("%d %d", &N, &K);
    for (i = 1; i <= N; i++) {
        scanf("%d", &numbers[i]);
        sum[i] = sum[i - 1] + numbers[i];
        if (i >= K) {
            T[i] = sum[i] - sum[(i - K)];
        }
    }
    for (i = K; i <= N; i++) {
        if (T[i] > ans)
            ans = T[i];
    }
    printf("%d", ans);
    return 0;
}