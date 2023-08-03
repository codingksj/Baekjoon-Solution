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
#include<iomanip>

using namespace std;

typedef long long LL;

LL Power(LL base, LL N) {
	int val = 1;
	for (int i = 0; i < N; i++) {
		val *= base;
	}
	return val;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	LL X, ans;
	cin >> X;
	ans = Power(X, 3);
	cout << ans;
	return 0;
}