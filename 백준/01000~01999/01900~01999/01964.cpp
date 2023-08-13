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
typedef long double LD;
typedef pair<int, int> Pii;
typedef pair<LL, LL> Pll;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	ULL old_dot, new_dot;
	const ULL MOD = 45678;
	int N;

	old_dot = 5;
	new_dot = old_dot;

	cin >> N;

	for (ULL i = 2; i <= N; i++) {
		new_dot = (old_dot + 4 + 3 * (i - 1)) % MOD;
		old_dot = new_dot;
	}
	
	cout << new_dot;

	return 0;
}