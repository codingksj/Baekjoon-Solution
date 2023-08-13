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

	vector<LL> sums;
	LL bird, sum, i, time = 0;

	sums.push_back(0);
	for (i = 1; i * (i + 1) <= 2 * (1E+9); i++) {
		sum = i * (i + 1) / 2;
		sums.push_back(sum);
	}

	cin >> bird;

	while (bird) {
		for (LL index = i - 1; index > 0; index--) {
			if (sums[index] <= bird) {
				time += index;
				bird -= sums[index];
				break;
			}
		}
	}

	cout << time;

	return 0;
}

