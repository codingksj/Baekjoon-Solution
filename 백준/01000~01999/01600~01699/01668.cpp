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

	vector<int> trophies;
	int trophy;
	int N;
	int left = 0, right = 0;
	int maxL = -1, maxR = -1;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> trophy;
		trophies.push_back(trophy);
	}

	for (int i = 0; i < N; i++) {
		if (trophies[i] > maxL) {
			maxL = trophies[i];
			left++;
		}
		if (trophies[N - 1 - i] > maxR) {
			maxR = trophies[N - 1 - i];
			right++;
		}
	}

	cout << left << "\n"
		<< right << "\n";

	return 0;
}

