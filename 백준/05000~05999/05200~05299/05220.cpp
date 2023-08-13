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

	int TC, count;
	LL N, check;
	string valid;

	cin >> TC;

	while (TC--) {
		count = 0;

		cin >> N >> check;
		N = ((N << 1) + check);
		for (LL i = 1; i <= N; i <<= 1) {
			(i & N) && count++;
		}
		valid = (count & 1) ? "Corrupt" : "Valid";
		cout << valid << "\n";
	}
	return 0;
}