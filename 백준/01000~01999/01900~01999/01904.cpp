#include <iostream>
using namespace std;

const int MAX = 1000000;
const long long MOD = 15746LL;

long long dp[MAX+1];

void ZeroOneTile(int N) {
    if (dp[N] == 0) {
        for (int i = 2; i <= N; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
            dp[i] %= MOD;
        }
    }
    printf("%lld\n",dp[N]);
}

int main() {
    dp[0] = 1LL;
    dp[1] = 1LL;
    int N;
    cin >> N;
    ZeroOneTile(N);

}