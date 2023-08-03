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

	LL a1, a2, a3;
	LL d, r;
	while (true) {
		cin >> a1 >> a2 >> a3;
		if (a1 == 0 && a2 == 0 && a3 == 0) {
			break;
		}
		if (a2 * a2 == a1 * a3) {
			r = a3 / a2;
			cout << "GP" << " " << a3 * r << "\n";
		}
		else {
			d = a3 - a2;
			cout << "AP" << " " << a3 + d << "\n";
		}
	}
	return 0;
}