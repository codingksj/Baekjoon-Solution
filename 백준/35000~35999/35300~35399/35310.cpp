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
	constexpr LL MOD = 998'244'353, INF = 0x3f3f3f3f;
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 3'000, CHANGE = ALPHABETS - 1;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

int dp[2][CHANGE * MAX + 1];
string s;
int N, M, res, cur = 1, prv;

int main() {
	FastIO();
	SetUp();

	Input();
	Solve();
	Output();

	return 0;
}

void FastIO() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	return;
};

void SetUp() {
	return;
};

bool Input() {
	cin >> N >> M >> s;

	return true;
};

void Solve() {
	M = min(M, N * CHANGE);
	for (int i = 0; i <= min(CHANGE, M); i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		const int LIM = min(i * CHANGE, M);
		cur = i & 1;
		prv = ~i & 1;
		LL sum = 0;
		int j = 0;
		memset(dp[cur], 0, sizeof(int) * (M + 1));
		for (; j <= CHANGE; j++) {
			sum += dp[prv][j];
			if (sum >= MOD) {
				sum -= MOD;
			}
			dp[cur][j] = sum;
		}
		for (; j <= LIM; j++) {
			sum += dp[prv][j] - dp[prv][j - CHANGE - 1];
			if (sum >= MOD) {
				sum -= MOD;
			}
			if (sum < 0) {
				sum += MOD;
			}
			dp[cur][j] = sum;
		}
	}
	for (int i : Rng(0, M + 1)) {
		res += dp[cur][i];
		if (res >= MOD) {
			res -= MOD;
		}
	}
	return;
};

void Output() {
	println("{}", res);
	return;
};
