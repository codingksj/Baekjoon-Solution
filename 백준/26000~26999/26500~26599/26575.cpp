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
#include<cstring>
#include<iomanip>

using namespace std;

typedef long long LL;
typedef pair<int, int> Pii;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int TC;
	double d, f, p;
	double cost;
	cin >> TC;
	while (TC--) {
		cin >> d >> f >> p;
		cost = d * f * p;
		cout.setf(ios:: fixed);
		cout.precision(2);
		cout << "$" << cost << "\n";
	}
	return 0;
}