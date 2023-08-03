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
	
	int A[4];
	int d1, d2;
	int ans;
	set<int> An;
	for (int i = 0; i < 3; i++) {
		cin >> A[i];
	}
	sort(A, A + 3);
	d1 = A[1] - A[0];
	d2 = A[2] - A[1];
	if (d1 > d2) {
		ans = A[0] + d2;
	}
	else if (d1 < d2) {
		ans = A[1] + d1;
	}
	else {
		ans = A[2] + d1;
	}
	cout << ans;
	return 0;
}