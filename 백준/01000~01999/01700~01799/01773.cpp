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
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> Pii;
typedef pair<LL, LL> Pll;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> periods;
	int N, C;
	int period;
	int time = 0;

	cin >> N >> C;
	while (N--) {
		cin >> period;
		periods.push_back(period);
	}

	for (int i = 1; i <= C; i++) {
		for (auto period : periods) {
			if (i % period == 0) {
				time++;
				break;
			}
		}
	}

	cout << time;

	return 0;
}

