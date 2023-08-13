#include <stdio.h>

#define SIZE 100002

int numbers[SIZE];
int sum[SIZE];

int main() {
    int N, M;
    int left, right;
    int i;
    int ans;
    scanf("%d %d", &N, &M);
    for (i = 1; i <= N; i++) {
        scanf("%d", &numbers[i]);
        sum[i] = sum[i - 1] + numbers[i];
    }
    for (i = 1; i <= M; i++) {
        scanf("%d %d", &left, &right);
        ans = sum[right] - sum[left - 1];
        printf("%d\n", ans);
    }
    return 0;
}