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

	LL A, B, C;
	while (true) {
		cin >> A >> B;
		if (A == 0 && B == 0) {
			break;
		}
		if (A > B) {
			swap(A, B);
		}
		C = 2LL * A - B;
		cout << C << "\n";
	}
	return 0;
}
