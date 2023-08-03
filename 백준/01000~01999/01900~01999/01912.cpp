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

#define MAX 100010
int dp[MAX], num[MAX];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	int maxV = -1001;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}
	for (int i = 1; i <= N; i++) {
		if (dp[i - 1] < 0) {
			dp[i] = num[i];
		}
		else {
			dp[i] = dp[i - 1] + num[i];
		}
		if (dp[i] >= maxV) {
			maxV = dp[i];
		}
	}
	cout << maxV;
	return 0;
}