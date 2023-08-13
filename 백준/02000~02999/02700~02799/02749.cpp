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

#define MAX 1500000ULL
#define MOD 1000000ULL

ULL dp[MAX + 10];

void GetFibonacci(ULL N);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	ULL N;

	GetFibonacci(MAX + 1);

	cin >> N;
	cout << dp[N % MAX];

	return 0;
}

void GetFibonacci(ULL N) {
	dp[0] = 0ULL;
	dp[1] = dp[2] = 1ULL;
	for (ULL i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}
};