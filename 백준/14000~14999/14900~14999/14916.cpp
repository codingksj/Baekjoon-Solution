#include<iostream>
#include<bitset>
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
typedef long double LD;
typedef pair<int, int> Pii;
typedef pair<LL, LL> Pll;

#define MAX 100001

int dp[MAX];

int GetExchange(int n);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;

	cin >> N;
	cout << GetExchange(N);

	return 0;
}

int GetExchange(int n) {
	dp[0] = -1;
	dp[1] = -1;
	dp[2] = 1;
	dp[3] = -1;
	dp[4] = 2;
	dp[5] = 1;
	dp[6] = 3;
	dp[7] = 2;
	dp[8] = 4;
	for (int i = 9; i <= n; i++) {
		dp[i] = dp[i - 5] + 1;
	}
	return dp[n];
};

