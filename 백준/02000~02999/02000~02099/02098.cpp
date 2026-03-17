#include<bits/stdc++.h>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
	constexpr string_view SEPS = " \n";
	constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
	constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f;
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 16;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
int DFS(int idx, int used);
void Output();

int dp[MAX][1 << MAX];
int C[MAX][MAX];
int N, res;

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
	cin >> N;

	for (int r : Rng(0, N)) {
		for (int c : Rng(0, N)) {
			cin >> C[r][c];
		}
	}

	return true;
};

void Solve() {
	res = DFS(0, 1 << 0);
};

int DFS(int idx, int used) {
	if (used == (1 << N) - 1) {
		return C[idx][0] ? C[idx][0] : INF;
	}
	int& val = dp[idx][used];
	if (val) {
		return val;
	}
	val = INF;
	for (int i = 0; i < N; i++) {
		if (!(used & (1 << i)) && C[idx][i]) {
			val = min(val, DFS(i, used | 1 << i) + C[idx][i]);
		}
	}
	return val;
};

void Output() {
	println("{}", res);
	return;
};
