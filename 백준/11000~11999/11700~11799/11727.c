#include<stdio.h>
int dp[1001];
int two_n(int n) {
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 5;

    for (int i = 4; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]*2)%10007;
    return dp[n];
       

}
int main() {
    int n;
    scanf("%d", &n);
    printf("%d", two_n(n));
    return 0;
}
