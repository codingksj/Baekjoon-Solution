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

ULL GCD(ULL a, ULL b) {
	if (b == 0) {
		return a;
	}
	return GCD(b, a % b);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	ULL A, B;
	ULL lcm;

	cin >> A >> B;

	lcm = (A * B) / GCD(A, B);

	cout << lcm;

	return 0;
}
