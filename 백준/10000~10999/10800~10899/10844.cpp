#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<string>
#include<numeric>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iomanip>

using namespace std;

typedef long long LL;
typedef pair<int, int> Pii;

#define LENGTH 102

int dp[LENGTH][10];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, result = 0;
	const int MOD = 1E+9;
	cin >> N;
	for (int i = 1; i < 10;i++) {
		dp[1][i] = 1;
	}
	for (int length = 2; length <= N; length++) {
		for (int digit = 0; digit < 10; digit++) {
			if (digit == 0) {
				dp[length][0] = dp[length - 1][1];
			}
			else if (digit == 9) {
				dp[length][9] = dp[length - 1][8];
			}
			else {
				dp[length][digit] = dp[length - 1][digit - 1] + dp[length - 1][digit + 1];
			}
			dp[length][digit] %= MOD;
		}
	}
	for (int digit = 0; digit < 10; digit++) {
		result = (result + dp[N][digit]) % MOD;
	}
	cout << result;
	return 0;
}