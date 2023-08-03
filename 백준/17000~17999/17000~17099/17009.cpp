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

LL calc(LL n1, LL n2, LL n3) {
	LL val;
	val = 3 * n1 + 2 * n2 + n3;
	return val;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	LL a1, a2, a3;
	LL b1, b2, b3;
	LL val1, val2;
	cin >> a1 >> a2 >> a3;
	cin >> b1 >> b2 >> b3;
	val1 = calc(a1, a2, a3);
	val2 = calc(b1, b2, b3);
	if (val1 > val2) {
		cout << 'A';
	}
	else if (val1 < val2) {
		cout << 'B';
	}
	else {
		cout << 'T';
	}
	return 0;
}