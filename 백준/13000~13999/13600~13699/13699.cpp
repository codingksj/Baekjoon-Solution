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

LL t[36];
LL GetT(int n);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	LL N;

	cin >> N;
	cout << GetT(N);

	return 0;
}

LL GetT(int n) {
	t[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			t[i] += (t[j] * t[i - j - 1]);
		}
	}
	return t[n];
};