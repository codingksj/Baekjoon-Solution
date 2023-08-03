#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

typedef long long LL;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	set<int> X, Y;
	int x, y;
	int dx, dy;
	int area;
	int TC;
	cin >> TC;
	while (TC--) {
		cin >> x >> y;
		X.insert(x);
		Y.insert(y);
	}
	dx = *X.rbegin() - *X.begin();
	dy = *Y.rbegin() - *Y.begin();
	area = dx * dy;
	cout << area << "\n";
	return 0;
}