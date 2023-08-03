#include <stdio.h>

#define MAX_SIZE 32
typedef unsigned long long ULL;

ULL dp[MAX_SIZE][MAX_SIZE];
ULL nCr(int n, int r) {
	// nCr = (n-1)C(r-1) + (n-1)C(r)
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= r; j++) {
			if (i == j || j == 0)
				dp[i][j] = 1LL;
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	return dp[n][r];

}

int main() {
	ULL ans;
	int N,M, TC;
	scanf("%d", &TC);
	while (TC--) {
	    scanf("%d %d",&N, &M);
		if ((M - N) < N) {
			N = (M - N);
		}
		ans = nCr(M, N);
		printf("%lld\n", ans);
	}
}