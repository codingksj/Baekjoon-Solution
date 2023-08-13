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

	int N;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		if (i % 15 == 0) {
			cout << "DeadMan" << "\n";
		}
		else if (i % 3 == 0) {
			cout << "Dead" << "\n";
		}
		else if (i % 5 == 0) {
			cout << "Man" << "\n";
		}
		else {
			cout << i << " ";
		}
	}
	return 0;
}