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
typedef pair<LL, LL> Pll;

bool IsValidCardNum(string& number);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string card;
	int TC;

	cin >> TC;

	while (TC--) {
		cin >> card;
		cout << (IsValidCardNum(card) ? 'T' : 'F') << "\n";
	}

	return 0;
}

bool IsValidCardNum(string& number) {
	int digit;
	int sum = 0;
	int maxL = number.length();

	reverse(number.begin(), number.end());

	for (int i = 0; i < maxL; i++) {
		digit = (number[i] - '0');
		if (i & 1) {
			digit = (digit * 2) % 10 + digit / 5;
		}
		sum += digit;
	}

	return !(sum % 10);
};
