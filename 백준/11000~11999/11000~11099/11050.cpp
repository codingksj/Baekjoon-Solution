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
typedef pair<int, int> Pii;
typedef pair<LL, LL> Pll;

ULL Factorial(ULL N);
ULL nCr(ULL n, ULL r);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	ULL n, r;
	cin >> n >> r;
	cout << nCr(n, r);
	return 0;
}

ULL Factorial(ULL N) {
	if (N == 0 || N == 1) {
		return 1LL;
	}
	else {
		return N * Factorial(N - 1);
	}
}

ULL nCr(ULL n, ULL r) {
	return Factorial(n) / (Factorial(r) * Factorial(n - r));
}