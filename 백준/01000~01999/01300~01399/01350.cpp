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

	LL TC, file, cluster;
	LL count = 0;
	vector<LL> files;

	cin >> TC;

	while (TC--) {
		cin >> file;
		files.push_back(file);
	}

	cin >> cluster;

	for (auto file : files) {
		count += ceil((double)file / cluster);
	}

	cout << count * cluster;

	return 0;
}
