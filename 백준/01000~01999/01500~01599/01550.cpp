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

	string hex;
	LL decimal = 0, weight = 1;
	LL val;
	bool isHex;

	cin >> hex;

	reverse(hex.begin(), hex.end());

	for (auto digit : hex) {
		isHex = (digit >= 'A' && digit <= 'F');
		val = isHex ? (digit - 'A' + 10) : (digit - '0');
		decimal += val * weight;
		weight *= 16;
	}

	cout << decimal;

	return 0;
}

