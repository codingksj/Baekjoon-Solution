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

	vector<int> A;
	int TC, N, X;
	cin >> TC >> X;
	while (TC--) {
		cin >> N;
		if (N < X) {
			A.push_back(N);
		}
	}
	for (auto e : A) {
		cout << e << " ";
	}
	return 0;
}