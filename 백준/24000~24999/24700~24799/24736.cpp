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
typedef pair<int, int> Pii;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int T, F, S, P, C;
	int visit, home;

	cin >> T >> F >> S >> P >> C;
	visit = 6 * T + 3 * F + 2 * S + P + 2 * C;
	cin >> T >> F >> S >> P >> C;
	home = 6 * T + 3 * F + 2 * S + P + 2 * C;

	cout << visit << "\n"
		<< home << "\n";
	return 0;
}