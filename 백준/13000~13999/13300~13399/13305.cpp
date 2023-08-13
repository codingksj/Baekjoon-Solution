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

	vector<LL> distances;
	LL N, price, min = 0;
	LL minV = 0, distance;

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		cin >> distance;
		distances.push_back(distance);
	}

	for (int i = 0; i < N - 1; i++) {
		cin >> price;
		if (i == 0 || price < min) {
			min = price;
		}
		minV += min * distances[i];
	}

	cout << minV;

	return 0;
}
