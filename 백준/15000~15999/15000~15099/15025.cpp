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
	
	int L, R;
	cin >> L >> R;
	if (L + R == 0) {
		cout << "Not a moose";
	}
	else {
		L == R ? cout << "Even " << L + R : cout << "Odd " << max(L, R) * 2;
	}

	return 0;
}