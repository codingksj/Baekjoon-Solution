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
typedef pair<LL, LL> Pll;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int TC, N;
	int col, row;
	int max;
	vector<int> rows(9,0);

	cin >> TC;

	while (TC--) {
		cin >> N;
		rows.assign(rows.size(), 0);
		max = 0;
		while (N--) {
			cin >> col >> row;
			rows[row]++;
		}
		max = *max_element(rows.begin(), rows.end());
		cout << max << "\n";
	}
	return 0;
}