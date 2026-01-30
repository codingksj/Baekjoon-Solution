#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using Vi = vector<int>;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

auto Rng = [](auto st, auto ed) { return views::iota(st, ed); };

const string SEPS = " \n";

Vi dp[5][5];
Vi A;
int N, K;

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
	dp[1][1] = { 1 };
	dp[2][2] = { 2, 1 };
	dp[3][1] = { 1, 2, 3 };
	dp[3][3] = { 3, 2, 1 };
	dp[4][1] = { 1, 4, 2, 3 };
	dp[4][2] = { 2, 1, 3, 4 };
	dp[4][4] = { 4, 3, 2, 1 };
	return;
};

bool Input() {
	cin >> N >> K;

	return true;
};

void Solve() {
	return;
}

void Output() {
	if (N <= 4) {
		A = dp[N][K];
		if (A.empty()) {
			println("-1");
			return;
		}
		for (int i = 0; i < N; i++) {
			print("{}{}", A[i], SEPS[i == N - 1]);
		}
		return;
	}
	if (K == N) {
		for (int i : Rng(1, N + 1) | views::reverse) {
			print("{}{}", i, SEPS[i == N - 1]);
		}
		return;
	}
	if (K == N - 1) {
		print("{} {} ", 1, N - 1);
		for (int i : Rng(2, N - 1)) {
			print("{} ", N - i);
		}
		println("{}", N);
		return;
	}
	for (int i : Rng(0, K + 1)) {
		print("{} ", K + 1 - i);
	}
	for (int i : Rng(K + 1, N - 1)) {
		print("{} ", i + 2);
	}
	println("{}", K + 2);
}
