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
	bool up, down, constant;
	int f1, f2, f3, f4;
	int d1, d2, d3;
	cin >> f1 >> f2 >> f3 >> f4;
	
	d1 = f2 - f1;
	d2 = f3 - f2;
	d3 = f4 - f3;

	up = d1 > 0 && d2 > 0 && d3 > 0;
	down = d1 < 0 && d2 < 0 && d3 < 0;
	constant = d1 == 0 && d2 == 0 && d3 == 0;

	if (up) {
		cout << "Fish Rising" << "\n";
	}
	else if (down) {
		cout << "Fish Diving" << "\n";
	}
	else if (constant) {
		cout << "Fish At Constant Depth" << "\n";
	}
	else {
		cout << "No Fish" << "\n";
	}
	return 0;
}