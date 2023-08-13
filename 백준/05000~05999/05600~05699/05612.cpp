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

	bool IsMinus = false;
	int N, M;
	int a, b;
	int max;

	cin >> N;
	cin >> M;
	
	max = M;
	while (N--) {
		cin >> a >> b;
		M += (a - b);
		if (M < 0) {
			IsMinus = true;
		}
		if (M > max) {
			max = M;
		}
	}
	max = IsMinus ? 0 : max;
	cout << max;

	return 0;
}
