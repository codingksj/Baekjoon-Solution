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
typedef pair<int, int> Pii;
typedef pair<LL, LL> Pll;

typedef struct _coord {
	int x;
	int y;
}Coord;

bool Cmp(const Coord& a, const Coord& b) {
	if (a.x == b.x) {
		return a.y < b.y;
	}
	return a.x < b.x;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<Coord> points;
	Coord point;
	int TC;

	cin >> TC;

	while (TC--) {
		cin >> point.x >> point.y;
		points.push_back(point);
	}

	sort(points.begin(), points.end(), Cmp);

	for (const Coord& point : points) {
		cout << point.x << " " << point.y << "\n";
	}

	return 0;
}
