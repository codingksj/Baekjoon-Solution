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
typedef pair<int, int> Pii;
typedef struct _coord {
	int x;
	int y;
}Coord;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	Coord A, B;
	int a, b;
	int distance;

	cin >> a >> b;

	A = { (a - 1) / 4, (a - 1) % 4 };
	B = { (b - 1) / 4, (b - 1) % 4 };

	distance = abs(B.y - A.y) + abs(B.x - A.x);

	cout << distance;

	return 0;
}