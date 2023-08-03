#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int dp[301];

int GetMaxScore(int n, int stair[]) {
	if (n == 0 || n == 1 || n == 2) {
		return dp[n];
	}
	else {
		for (int i = 3; i <= n; i++) {
			int case1 = dp[i - 2] + stair[i];
			int case2 = dp[i - 3] + stair[i - 1] + stair[i];
			dp[i] = max(case1, case2);
		}
	}
	return dp[n];
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int maxV;
	int stair[301];
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> stair[i];
	}
	dp[0] = 0;
	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];
	maxV = GetMaxScore(N, stair);
	cout << maxV << "\n";
	return 0;
}