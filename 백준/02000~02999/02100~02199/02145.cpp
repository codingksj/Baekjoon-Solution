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

int GetOneDigitNum(int N);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;

	while (true) {
		cin >> N;
		if (N == 0) {
			break;
		}
		cout << GetOneDigitNum(N) << "\n";
	}

	return 0;
}

int GetOneDigitNum(int N) {
	int curN = N;
	int sumOfDigit;
	while (curN > 9) {
		sumOfDigit = 0;
		while (curN) {
			sumOfDigit += (curN % 10);
			curN /= 10;
		}
		curN = sumOfDigit;
	}
	return curN;
};
