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
typedef pair<int, int> Pii;
typedef pair<LL, LL> Pll;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, m, M, T, R;
	int time = 0, heartbeat;

	cin >> N >> m >> M >> T >> R;

	if (M - m < T) {
		cout << -1;
		return 0;
	}

	heartbeat = m;

	while (N) {
		if (heartbeat + T <= M) {
			heartbeat += T;
			N--;
		}
		else {
			heartbeat -= R;
			if (heartbeat < m) {
				heartbeat = m;
			}
		}
		time++;
	}
	cout << time;
	return 0;
}
