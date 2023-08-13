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

int GCD(int a, int b) {
	if (b == 0) {
		return a;
	}
	return GCD(b, a % b);
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int TC;
	int a, b;
	int gcd, lcm;

	cin >> TC;

	while (TC--) {
		cin >> a >> b;

		gcd = GCD(a, b);
		lcm = a * b / gcd;

		cout << lcm << " " << gcd << "\n";
	}

	return 0;
}

