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
typedef pair<LL, LL> Pll;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int baskets[101] = { 0, };
	int N, M;
	int i, j, k;

	cin >> N >> M;
	while (M--) {
		cin >> i >> j >> k;
		fill(baskets + i, baskets + j+1, k);
	}
	for (int i = 1; i <= N; i++) {
		cout << baskets[i] << " ";
	}
	return 0;
}

