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

#define DAY 1440
#define HOUR 60

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int D, H, M;
	int total;
	cin >> D >> H >> M;
	total = (D - 11) * DAY + (H - 11) * HOUR + (M - 11);
	if (total < 0) {
		cout << -1 << "\n";
	}
	else {
		cout << total << "\n";
	}
	return 0;
}