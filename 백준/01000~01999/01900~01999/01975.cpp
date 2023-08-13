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

LL CountTotalZero(int N);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int TC;
	int N;

	cin >> TC;

	while (TC--) {
		cin >> N;
		cout << CountTotalZero(N) << "\n";
	}
	
	return 0;
}

LL CountTotalZero(int N) {
	int base, curN, count;
	LL total = 0;
	if (N == 1) {
		return 0;
	}
	for (base = 2; base <= N; base++) {
		curN = N;
		count = 0;
		while (curN) {
			if (curN % base) {
				break;
			}
			curN /= base;
			count++;
		}
		total += count;
	}
	return total;
};