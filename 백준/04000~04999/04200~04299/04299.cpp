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

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	bool cond1, cond2;
	int x, y, n, m;
	cin >> n >> m;
	cond1 = (n + m) % 2 == 0;
	cond2 = (n >= m);

	x = (n + m) / 2;
	y = (n - m) / 2;
	if (x < y) {
		swap(x, y);
	}
	if (cond1 && cond2) {
		cout << x << " " << y << "\n";
	}
	else {
		cout << -1;
	}
	return 0;
}