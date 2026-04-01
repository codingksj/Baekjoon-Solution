#include<bits/stdc++.h>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
using Ti3 = tuple<int, int, int>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
	constexpr string_view SEPS = " \n";
	constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
	constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f;
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 1E+6;
	constexpr auto Rng = views::iota;
	constexpr auto Rev = views::reverse;
	constexpr auto Split = views::split;
	enum CASES { ALL, ZOS, ONES };
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

LL dp[3][MAX + 1];
int S[3];
int TC, H, N, res;

int main() {
	FastIO();
	SetUp();

	cin >> TC;

	while(TC--){
		Input();
		Solve();
		Output();
	}

	return 0;
}

void FastIO() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	return;
};

void SetUp() {
	for (int i = 0; i < 3; i++) {
		dp[i][0] = dp[i][1] = 1;
	}
	for (int h = 2; h <= MAX; h++) {
		dp[ALL][h] = (dp[ALL][h - 1] * dp[ALL][h - 1] + 2 * dp[ALL][h - 1] * dp[ALL][h - 2]) % MOD;
		dp[ZOS][h] = (dp[ZOS][h - 1] * dp[ZOS][h - 1] + dp[ZOS][h - 1] * dp[ZOS][h - 2]) % MOD;
		dp[ONES][h] = (2 * dp[ONES][h - 1] * dp[ONES][h - 2]) % MOD;
	}
	return;
};

bool Input() {
	cin >> H >> N;

	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}

	return true;
};

void Solve() {
	switch (N) {
		case 3: res = dp[ALL][H]; return;
		case 2: res = (S[0] + S[1]) ? dp[ZOS][H] : dp[ONES][H]; return;
		default: res = 1; return;
	}
	return;
};

void Output() {
	println("{}", res);
	return;
};
