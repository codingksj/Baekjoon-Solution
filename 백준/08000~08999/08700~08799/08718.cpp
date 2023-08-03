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

#define ML 1000

typedef long long LL;
typedef pair<int, int> Pii;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int x, k;
	int small, medium, big;
	int snowman;
	cin >> x >> k;
	x *= ML;
	k *= ML;
	small = 7 * k / 4;
	medium = 7 * k / 2;
	big = 7 * k;
	if (small <= x) {
		snowman = small;
	}
	if (medium <= x) {
		snowman = medium;
	}
	if (big <= x) {
		snowman = big;
	}
	cout << snowman;
	return 0;
}