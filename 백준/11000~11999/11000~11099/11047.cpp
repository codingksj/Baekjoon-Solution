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

	int N, price, i, coins;
	int count = 0;
	int w[11] = { 0, };

	cin >> N >> price;
	for (i = 1; i <= N; i++) {
		cin >> w[i];
	}
	i = N;
	while (price) {
		if (w[i] > price) {
			i--;
			continue;
		}
		coins = price / w[i];
		count += coins;
		price -= w[i] * coins;
	}
	cout << count;
	return 0;
}

