#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    int arr[1025][1025];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    int dp[1025][1025] = {0};
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + arr[i][j];
        }
    }
    
    while (M--) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int sum = dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
        printf("%d\n", sum);
    }
    
    return 0;
}
