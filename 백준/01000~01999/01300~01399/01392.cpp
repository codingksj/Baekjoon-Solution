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

	vector<int> times;

	int time;
	int N, Q;

	cin >> N >> Q;

	for (int i = 1; i <= N; i++) {
		cin >> time;
		while (time--) {
			times.push_back(i);
		}
	}

	while (Q--) {
		cin >> time;
		cout << times[time] << "\n";
	}

	return 0;
}

