#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<string>
#include<numeric>
#include<cmath>
#include<cctype>
#include<iomanip>

using namespace std;

typedef long long LL;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	LL N, case1, case2;
	cin >> N;
	case1 = N * 78 / 100;
	case2 = N * 80 / 100 + N * 20 / 100 * 78 / 100;
	cout << case1 << "\n"
		<< case2 << "\n";
	return 0;
}