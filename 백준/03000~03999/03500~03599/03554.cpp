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

#define MAX 50002
#define MOD 2010LL

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	LL a[MAX], sum;

	int N, M;
	int op, left, right;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	cin >> M;
	while (M--) {
		sum = 0;
		cin >> op >> left >> right;
		if (op == 1) {
			for (int i = left; i <= right; i++) {
				a[i] = (a[i] * a[i]) % MOD;
			}
		}
		else {
			for (int i = left; i <= right; i++) {
				sum += a[i];
			}
			cout << sum << "\n";
		}
	}
	return 0;
}