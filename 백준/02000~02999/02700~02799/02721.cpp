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

LL W(LL n) {
	return (n * (n + 1) * (n + 2) * (n + 3) / 8);
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	LL TC, n;

	cin >> TC;
	while (TC--) {
		cin >> n;
		cout << W(n) << "\n";
	}
	return 0;
}