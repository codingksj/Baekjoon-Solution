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
	LL TC;
	LL num, speed, day;
	LL distance, value;
	LL sum;
	vector<LL> ships;
	Pii ship;
	cin >> TC;
	for (LL i = 1; i <= TC; i++) {
		ships.clear();
		cin >> num >> speed >> day;
		while (num--) {
			cin >> distance >> value;
			if (distance <= day * speed) {
				ships.push_back(value);
			}
		}
		sum = accumulate(ships.begin(), ships.end(), 0);
		cout << "Data Set" << " " << i << ":\n" << sum << "\n\n";
	}
	return 0;
}