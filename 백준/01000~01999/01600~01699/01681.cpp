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

	ULL N, L, curN;
	ULL num = 1;
	ULL count = 0;
	vector<ULL> numbers;
	bool find;

	cin >> N >> L;

	while (count < N) {
		find = false;
		curN = num;
		while (curN) {
			if (curN % 10 == L) {
				find = true;
				break;
			}
			curN /= 10;
		}
		if (find) {
			num++;
			continue;
		}
		numbers.push_back(num);
		num++;
		count++;
	}

	cout << numbers[N - 1];

	return 0;
}

