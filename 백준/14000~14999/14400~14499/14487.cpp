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

	int village;
	int TC, answer;
	int maxV = -1;
	int sum = 0;

	cin >> TC;

	while (TC--) {
		cin >> village;
		sum += village;
		if (village > maxV) {
			maxV = village;
		}
	}

	answer = sum - maxV;

	cout << answer;

	return 0;
}

