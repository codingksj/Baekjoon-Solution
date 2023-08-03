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
	LL factorial = 1;
	cin >> N;
	if (N == 0 || N == 1) {}
	else if (N < 5) {
		for (LL i = 2; i <= N; i++) {
			factorial *= i;
		}
		factorial %= 10;
	}
	else {
		factorial = 0;
	}
	cout << factorial;
	return 0;
}