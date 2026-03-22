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
	constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f;
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 1E+5;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

int dp[2][5][5];
int mv[5][5];
int N, res = INF;

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
	for (int i : Rng(0, 5)) {
		for (int j : Rng(0, 5)) {
			int& c = mv[i][j];
			if (i == j) {
				c = 1;
			}
			else if (i == 0 || j == 0){
				c = 2;
			}
			else {
				c = 3 + (~abs(i - j) & 1);
			}
		}
	}
	return;
};

bool Input() {
	return true;
};

void Solve() {
	memset(dp[0], 0x3f, sizeof(dp[0]));
	dp[0][0][0] = 0;
	auto GetCost = [](int idx, int target) {
		int cur = idx & 1;
		int prv = ~idx & 1;
		memset(dp[cur], 0x3f, sizeof(dp[cur]));
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (dp[prv][i][j] == INF) {
					continue;
				}
				if (target != j) {
					dp[cur][target][j] = min(dp[cur][target][j], dp[prv][i][j] + mv[i][target]);
				}
				if (target != i) {
					dp[cur][i][target] = min(dp[cur][i][target], dp[prv][i][j] + mv[j][target]);
				}
				
			}
		}
	};
	int cnt = 0;
	while (cin >> N && N) {
		GetCost(++cnt, N);
	}
	for (int i : Rng(0, 5)) {
		for (int j : Rng(0, 5)) {
			res = min(res, dp[cnt & 1][i][j]);
		}
	}
	return;
};

void Output() {
	println("{}", res);
	return;
};
