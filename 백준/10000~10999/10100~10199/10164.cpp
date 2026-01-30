#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using Vi = vector<int>;
using VVi = vector<Vi>;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

auto Rng = [](auto st, auto ed) { return views::iota(st, ed); };

const int DOTS = 4;

VVi dp;
int N, M, K;

int main() {
	FastIO();
	SetUp();

	Input();
	Solve();
	Output();

	return 0;
}

void FastIO() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
};

void SetUp() {
	return;
};

bool Input() {
	cin >> N >> M >> K;

	dp = VVi(N, Vi(M));

	return true;
};

void Solve() {
	dp[0][0] = 1;
	int tr, tc;
	if (!K) {
		tr = tc = 0;
	}
	else if (N > 1 && M > 1) {
		tr = (K - 1) / M;
		tc = (K - 1) % M;
	}
	else {
		tr = N == 1 ? 0 : K - 1;
		tc = M == 1 ? 0 : K - 1;
	}
	for (int r = 0; r <= tr; r++) {
		for (int c = 0; c <= tc; c++) {
			if (r > 0) {
				dp[r][c] += dp[r - 1][c];
			}
			if (c > 0) {
				dp[r][c] += dp[r][c - 1];
			}
		}
	}
	for (int r = tr; r < N; r++) {
		for (int c = tc; c < M; c++) {
			if (r == tr && c == tc) {
				continue;
			}
			if (r > 0) {
				dp[r][c] += dp[r - 1][c];
			}
			if (c > 0) {
				dp[r][c] += dp[r][c - 1];
			}
		}
	}
};

void Output() {
	println("{}", dp[N - 1][M - 1]);
}
