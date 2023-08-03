#include<stdio.h>
long long dp[1001];
long long wave(int n) {
    dp[1] = 1LL;
    dp[2] = 1LL;
    dp[3] = 1LL;
    dp[4] = 2LL;
    dp[5] = 2LL;
    
    for (int i = 6; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 5]);
    return dp[n];
       

}
int main() {
    int TC, n;
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d", &n);
        printf("%llu\n", wave(n));
    }
    return 0;
}
