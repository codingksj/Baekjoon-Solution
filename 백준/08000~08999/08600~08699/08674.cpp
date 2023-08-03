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

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	LL w, h;
	LL left, right;
	LL up, down;
	LL rectangle;
	
	cin >> w >> h;
	rectangle = w * h;

	left = w / 2 * h;
	right = rectangle - left;

	up = h / 2 * w;
	down = rectangle - up;

	cout << min(right - left, down - up);
	return 0;
}