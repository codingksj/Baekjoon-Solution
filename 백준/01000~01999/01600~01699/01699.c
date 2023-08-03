#include <stdio.h>

#define MAX 100001

typedef long long LL;

LL min(LL a, LL b) {
    if (a < b) {
        return a;
    }
    return b;
}

LL dp[MAX];

int main(){
    LL N;
    scanf("%lld", &N);
 
    for (LL i = 1; i <= N; i++) {
        dp[i] = i;
    }
    for (LL i = 1; i <= N; i++) {
        for (LL j = 1; j * j <= i; j--) {
            dp[i] = min(dp[i - j * j] + 1, dp[i]);
        }
    }
    printf("%lld\n", dp[N]);
    return 0;
}