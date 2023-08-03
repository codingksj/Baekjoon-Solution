#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<string>
#include<numeric>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iomanip>

using namespace std;

typedef long long LL;
typedef pair<int, int> Pii;

#define MAX 10002

int dp[MAX];
int wine[MAX];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> wine[i];
	}
	dp[1] = wine[1];
	dp[2] = dp[1] + wine[2];
	for (int i = 3; i <= N; i++) {
		dp[i] = max(dp[i - 3] + wine[i - 1] + wine[i], max(dp[i - 2] + wine[i], dp[i - 1]));
	}
	cout << dp[N];
	return 0;
}