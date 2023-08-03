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

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	double pastT, nowT, dT;
	for (LL i = 0;; i++) {
		cin >> nowT;
		if (nowT == 999) {
			break;
		}
		if (i == 0) {
			pastT = nowT;
			continue;
		}
		dT = nowT - pastT;
		pastT = nowT;
		cout << fixed;
		cout.precision(2);
		cout << dT << "\n";
	}
	
	return 0;
}