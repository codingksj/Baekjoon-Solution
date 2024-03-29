#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int arr[301][301];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int TC;
    scanf("%d", &TC);

    int dp[301][301] = { 0 };
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + arr[i][j];
        }
    }

    while (TC--) {
        int i, j, x, y;
        scanf("%d %d %d %d", &i, &j, &x, &y);
        int sum = dp[x][y] - dp[i - 1][y] - dp[x][j - 1] + dp[i - 1][j - 1];
        printf("%d\n", sum);
    }

    return 0;
}
