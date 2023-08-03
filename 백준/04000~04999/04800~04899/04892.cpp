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

	int n[5];
	for (LL i = 1;;i++) {
		cin >> n[0];
		if (n[0] == 0) {
			break;
		}
		n[1] = 3 * n[0];
		n[2] = n[1] & 1 ? n[1] / 2 : (n[1] + 1) / 2;
		n[3] = 3 * n[2];
		n[4] = n[3] / 9;
		cout << i << ". " << (n[1] & 1 ? "odd" : "even") << " " << n[4] << "\n";
	}
	return 0;
}