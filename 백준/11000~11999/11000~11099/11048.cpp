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
typedef pair<LL, LL> Pll;

#define MAX 1002

int maze[MAX][MAX];
int dp[MAX][MAX];

int Solve(int N, int M);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> maze[i][j];
		}
	}
	cout << Solve(N, M);
	return 0;
}

int Solve(int N, int M) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = maze[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[N][M];
};
