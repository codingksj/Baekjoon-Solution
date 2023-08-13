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

	LL N, K;
	LL bonus;
	LL chicken = 0;

	while (cin >> N >> K) {
		chicken = N;
		while (!(N < K)) {
			bonus = N / K;
			chicken += bonus;
			N = bonus + N % K;
		}
		cout << chicken << "\n";
	}

	return 0;
}

