#include<iostream>
#include<set>
#include<unordered_map>
#include<map>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<algorithm>
#include<string>
#include<numeric>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iomanip>
#include<chrono>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> Pii;
typedef pair<LL, LL> Pll;

#define MAX 1011
#define MOD 10007ULL

ULL dp[MAX][MAX];

ULL nCr(ULL n, ULL r);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	ULL n;
	cin >> n;
	cout << nCr(n+9, n);
	return 0;
}

ULL nCr(ULL n, ULL r) {
	dp[0][0] = dp[1][0] = dp[1][1] = 1ULL;
	if (n == r || r == 0) {
		return 1ULL;
	}
	else {
		for (ULL i = 2; i <= n; i++) {
			for (ULL j = 0; j <= i; j++) {
				if (j == 0 || j == i) {
					dp[i][j] = 1LL;
				}
				else {
					dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
				}
			}
		}
		return dp[n][r];
	}
}