#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

int dp[12];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int TC, N;
	cin >> TC;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 11; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	while (TC--) {
		cin >> N;
		cout << dp[N] << "\n";
	}
	return 0;
}