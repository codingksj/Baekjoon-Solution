#include<iostream>
#include<bitset>
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
typedef pair<LL, LL> PLL;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> line;
	int N, gacha;
	int newPos;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> gacha;
		newPos = i - gacha;
		line.insert(line.begin() + newPos, i + 1);
	}
	for (auto student : line) {
		cout << student << " ";
	}
	return 0;
}

