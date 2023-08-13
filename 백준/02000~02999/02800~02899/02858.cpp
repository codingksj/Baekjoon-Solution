#include<iostream>
#include<sstream>
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

set<int> FindDivisors(int N);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	set<int> divisors;
	int R, B, N;
	int newR, newB;
	int L, W;

	cin >> R >> B;
	N = R + B;

	divisors = FindDivisors(N);

	for (auto e : divisors) {
		L = N / e;
		W = e;
		if (W > L) {
			swap(W, L);
		}
		if (L < 3 || W < 3) {
			continue;
		}
		newB = (L - 2) * (W - 2);
		newR = N - B;
		if (R == newR && B == newB) {
			cout << L << " " << W << "\n";
			break;
		}
	}

	return 0;
}

set<int> FindDivisors(int N){
	set<int> divisors;
	for (int i = 1; i <= sqrt(N); i++) {
		if (N % i) {
			continue;
		}
		divisors.insert(i);
	}
	return divisors;
};