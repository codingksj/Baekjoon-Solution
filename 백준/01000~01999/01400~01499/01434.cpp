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

	int N, M;
	LL box, book;
	LL sumOfBox = 0;
	LL sumOfBook = 0;

	cin >> N >> M;

	while (N--) {
		cin >> box;
		sumOfBox += box;
	}

	while (M--) {
		cin >> book;
		sumOfBook += book;
	}

	cout << sumOfBox - sumOfBook;
	return 0;
}

