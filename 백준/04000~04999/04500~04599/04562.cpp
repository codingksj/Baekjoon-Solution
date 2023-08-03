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
	int demand, supply;
	const string brain = " BRAINS";
	cin >> TC;
	while (TC--) {
		cin >> supply >> demand;
		if (supply < demand) {
			cout << "NO" + brain << "\n";
		}
		else {
			cout << "MMM" + brain << "\n";
		}
	}
	return 0;
}