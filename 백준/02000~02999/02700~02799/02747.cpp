#include<iostream>
#include<sstream>
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
typedef pair<LL, LL> PLL;

ULL dp[50];
ULL Fibonacci(ULL N);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	ULL N;

	cin >> N;
	cout << Fibonacci(N);

	return 0;
}

ULL Fibonacci(ULL N) {
	dp[0] = 0ULL;
	dp[1] = dp[2] = 1ULL;
	if (N > 2) {
		for (ULL i = 3; i <= N; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
	}
	return dp[N];
};