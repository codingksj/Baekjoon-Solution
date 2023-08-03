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

	int X, L, R;
	int left, right;
	cin >> X >> L >> R;
	left = min(L, R);
	right = max(L, R);
	if (left > X) {
		cout << left;
	}
	else if (right < X) {
		cout << right;
	}
	else {
		cout << X;
	}
	return 0;
}