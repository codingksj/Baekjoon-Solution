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

bool Calc(LL n1, char op, LL n2, LL ans);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	LL TC;
	LL n1, n2, ans;
	char op, eq;

	cin >> TC;

	while (TC--) {
		cin >> n1 >> op >> n2 >> eq >> ans;
		cout << (Calc(n1, op, n2, ans) ? "correct" : "wrong answer") << "\n";
	}

	return 0;
}

bool Calc(LL n1, char op, LL n2, LL ans) {
	if (op == '+') {
		return (n1 + n2 == ans);
	}
	else if (op == '-') {
		return (n1 - n2 == ans);
	}
	else if (op == '*') {
		return (n1 * n2 == ans);
	}
	else {
		return (n1 / n2 == ans);
	}
};
