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
	LL N;
	cin >> N;
	for (LL i = 1; i <= N; i++) {
		cout << i << " ";
		if (i % 6 == 0 || i == N) {
			cout << "Go!" << " ";
		}
	}
	return 0;
}