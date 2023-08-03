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
	int A, B, C, D, E;
	int total = 0;
	cin >> A >> B >> C >> D >> E;
	if (A < 0) {
		total = abs(A) * C + D + B * E;
	}
	else {
		total = (B - A) * E;
	}
	cout << total;
	return 0;
}