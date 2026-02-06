#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
	constexpr string_view SEPS = " \n";
	constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
	constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f;
	constexpr int DIGITS = 10, MAX = 50;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}

using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

LL C[MAX + 2][MAX + 2];
LL powMods[MAX + 2] = { 1, };
LL invMods[MAX + 2] = { 1, 1, };
LL dp[MAX + 1];
LL N, K;

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
	for (LL i : Rng(0, MAX + 2)) {
		C[i][0] = 1;
		for (LL j = 1; j <= i; j++) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
		}
	}
	return;
};

bool Input() {
	cin >> N >> K;

	return true;
};

void Solve() {
	for (int i : Rng(1, K + 2)) {
		powMods[i] = powMods[i - 1] * (N + 1) % MOD;
	}
	for (int i : Rng(2, K + 2)) {
		invMods[i] = (MOD - MOD / i) * invMods[MOD % i] % MOD;
	}
	dp[0] = N;
	for (int k : Rng(1, K + 1)) {
		dp[k] = powMods[k + 1] - 1;
		if (dp[k] < 0) {
			dp[k] += MOD;
		}
		for (int i : Rng(2, k + 2)) {
			LL val = C[k + 1][i] * dp[k - i + 1] % MOD;
			dp[k] -= val;
			if (dp[k] < 0) {
				dp[k] += MOD;
			}
		}
		dp[k] = dp[k] * invMods[k + 1] % MOD;
	}
	return;
}

void Output() {
	println("{}", dp[K]);
	return;
}
