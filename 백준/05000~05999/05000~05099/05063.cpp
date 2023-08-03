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

	int TC;
	int r, e, c;
	string ad;
	cin >> TC;
	while (TC--) {
		cin >> r >> e >> c;
		if (r < e - c) {
			ad = "advertise";
		}
		else if (r > e - c) {
			ad = "do not advertise";
		}
		else {
			ad = "does not matter";
		}
		cout << ad << "\n";
	}
	return 0;
}