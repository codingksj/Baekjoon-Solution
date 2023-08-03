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
	double x, y;
	string Q;
	while (true) {
		cin >> x >> y;
		if (x == 0 && y == 0) {
			cout << "AXIS" << "\n";
			break;
		}
		if (x == 0 || y == 0) {
			cout << "AXIS" << "\n";
			continue;
		}
		(x > 0) ? (y > 0) ? Q = "Q1" : Q = "Q4": (y > 0) ? Q = "Q2" : Q = "Q3";
		cout << Q << "\n";
	}
	return 0;
}