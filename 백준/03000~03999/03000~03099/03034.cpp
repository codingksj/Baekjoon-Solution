#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int TC, x, y, match;
	int limit_len, match_len;
	cin >> TC >> x >> y;
	limit_len = x * x + y * y;
	while (TC--) {
		cin >> match;
		match_len = match * match;
		if (limit_len < match_len) {
			cout << "NE" << "\n";
		}
		else {
			cout << "DA" << "\n";
		}
	}
	return 0;
}