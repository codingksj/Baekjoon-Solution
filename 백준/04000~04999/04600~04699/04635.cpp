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
	int delta, mile, pastHour, nowHour, total;

	while (true) {
		cin >> TC;
		pastHour = 0;
		total = 0;
		if (TC < 0) {
			break;
		}
		while (TC--) {
			cin >> mile >> nowHour;
			delta = nowHour - pastHour;
			total += delta * mile;
			pastHour = nowHour;
		}
		cout << total << " miles" << "\n";
	}
	return 0;
}