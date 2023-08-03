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

#define MAX 502

int dp[MAX][MAX];
int triangle[MAX][MAX];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, maxV = 0;
	cin >> N;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= r; c++) {
			cin >> triangle[r][c];
		}
	}
	dp[1][1] = triangle[1][1];
	for (int r = 2; r <= N; r++) {
		for (int c = 1; c <= r; c++) {
			dp[r][c] = max(dp[r - 1][c - 1], dp[r - 1][c]) + triangle[r][c];
		}
	}
	for (int i = 1; i <= N; i++) {
		if (maxV < dp[N][i]) {
			maxV = dp[N][i];
		}
	}
	cout << maxV << "\n";
	return 0;
}