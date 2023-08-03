#include<stdio.h>
long long dp[100];
long long fibo(int n) {
    dp[0] = 0LL;
    dp[1] = 1LL;
    int i;
    for (i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%llu", fibo(n));
    return 0;
}
