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
	constexpr int DIGITS = 10, MAX = 1'000;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}

using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

LL powMods[MAX + 2] = { 1, };
LL invMods[MAX + 2] = { 1, 1, };
LL f[MAX + 2] = { 1, 1, };
LL invF[MAX + 2] = { 1, 1, };
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
		f[i] = f[i - 1] * i % MOD;
		invF[i] = invF[i - 1] * invMods[i] % MOD;
	}
	auto Comb = [&](LL n, LL r) {
		return f[n] * invF[r] % MOD * invF[n - r] % MOD;
	};
	dp[0] = N;
	for (int k : Rng(1, K + 1)) {
		dp[k] = powMods[k + 1] - 1;
		if (dp[k] < 0) {
			dp[k] += MOD;
		}
		for (int i : Rng(2, k + 2)) {
			LL val = Comb(k + 1, i) * dp[k - i + 1] % MOD;
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
