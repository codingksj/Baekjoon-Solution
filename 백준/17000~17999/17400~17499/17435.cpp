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
	constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX_N = 5E+5, MAX_M = 2E+5;
	constexpr int DIGITS = 10, ALPHABETS = 26;
	constexpr auto Rng = views::iota;
	constexpr auto Rev = views::reverse;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

int F[bit_width(MAX_N) + 1][MAX_M + 1];
int M, Q, sz, n, x;

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
	cin >> M;

	for (int i : Rng(1, M + 1)) {
		cin >> F[0][i];
	}
	cin >> Q;

	return true;
};

void Solve() {
	int mxLv = bit_width(MAX_N) + 1;
	for (int lv : Rng(1, mxLv)) {
		for (int i = 1; i <= M; i++) {
			F[lv][i] = F[lv - 1][F[lv - 1][i]];
		}
	}
	auto Query = [](int n, int x) {
		for (int depth = 0; n; depth++, n >>= 1) {
			if (n & 1) {
				x = F[depth][x];
			}
		}
		return x;
	};
	while (Q--) {
		cin >> n >> x;
		println("{}", Query(n, x));
	}
	return;
};

void Output() {
	return;
};
