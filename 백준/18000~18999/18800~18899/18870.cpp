#include<iostream>
#include<sstream>
#include<bitset>
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
typedef pair<LL, LL> PLL;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	set<LL> coords;
	vector<LL> X, table;
	LL x;
	int TC;
	int left, mid, right;
	int size;

	cin >> TC;

	while (TC--) {
		cin >> x;
		X.push_back(x);
		coords.insert(x);
	}
	table = vector<LL>(coords.begin(), coords.end());
	coords.clear();
	size = table.size();

	for (LL x : X) {
		left = 0;
		right = size - 1;

		while (left <= right) {
			mid = (left + right) / 2;

			if (table[mid] == x) {
				cout << mid << " ";
				break;
			}
			else if (table[mid] < x) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
	}
    return 0;
}
