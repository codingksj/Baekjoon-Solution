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
#include<iomanip>

using namespace std;

typedef long long LL;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int TC;
	LL a, b;
	cin >> TC;
	while (TC--) {
		cin >> a >> b;
		cout << a + b << "\n";
	}
	return 0;
}