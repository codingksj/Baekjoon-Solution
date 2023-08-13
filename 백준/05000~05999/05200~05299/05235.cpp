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
typedef pair<LL, LL> Pll;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int TC, N;
	LL input, oddSum, evenSum;

	cin >> TC;

	while (TC--) {
		oddSum = evenSum = 0;
		cin >> N;
		while (N--) {
			cin >> input;
			(input & 1) ? oddSum += input : evenSum += input;
		}
		cout << (evenSum > oddSum ? "EVEN" : (evenSum < oddSum ? "ODD" : "TIE")) << "\n";
	}
	return 0;
}