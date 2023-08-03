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
	LL layer, sum = 0;
	while (true) {
		cin >> layer;
		if (layer == 0) {
			break;
		}
		sum = layer * (layer + 1LL) / 2;
		cout << sum << "\n";
	}
	return 0;
}