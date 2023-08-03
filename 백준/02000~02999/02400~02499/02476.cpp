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
	int d1, d2, d3;
	int same;
	int amount;
	vector<int> prize;

	cin >> TC;
	while (TC--) {
		cin >> d1 >> d2 >> d3;
		if (d1 == d2 && d2 == d3) {
			same = d1;
			amount = 10000 + same * 1000;
		}
		else if (d1 == d2 || d2 == d3 || d3 == d1) {
			same = (d1 == d2) ? d1 : d3;
			amount = 1000 + same * 100;
		}
		else {
			amount = 100 * max(d1, max(d2, d3));
		}
		prize.push_back(amount);
	}
	cout << *max_element(prize.begin(), prize.end());
	
	return 0;
}