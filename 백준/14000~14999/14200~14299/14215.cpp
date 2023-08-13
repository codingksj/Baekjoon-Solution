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

	int a, b, c;
	
	cin >> a >> b >> c;

	if (a > b) {
		swap(a, b);
	}

	if (b > c) {
		swap(b, c);
	}

	cout << ((a + b) > c ? a + b + c : 2 * (a + b) - 1);

	return 0;
}

