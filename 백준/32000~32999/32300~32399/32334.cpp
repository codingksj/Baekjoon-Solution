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
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 1000;
	constexpr auto Rng = views::iota;
	constexpr auto Rev = views::reverse;
	constexpr auto Split = views::split;
	constexpr auto Take = views::take;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

int pfA[MAX + 1][MAX + 1];
bool A[MAX + 1][MAX + 1];
Pii pos;
int N, D, mnMagnet = INF;

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
	cin >> N >> D;

	for (int r : Rng(1, N + 1)) {
		for (int c : Rng(1, N + 1)) {
			cin >> A[r][c];
			pfA[r][c] = A[r][c] + pfA[r - 1][c] + pfA[r][c - 1] - pfA[r - 1][c - 1];
		}
	}
	return true;
};

void Solve() {
	auto Query = [](int r1, int c1, int r2, int c2) {
		return pfA[r2][c2] - pfA[r1 - 1][c2] - pfA[r2][c1 - 1] + pfA[r1 - 1][c1 - 1];
	};
	for (int r : Rng(1, N + 1)) {
		for (int c : Rng(1, N + 1)) {
			if (A[r][c]) {
				continue;
			}
			int magnet = Query(max(1, r - D), max(1, c - D), min(N, r + D), min(N, c + D));
			if (magnet < mnMagnet) {
				mnMagnet = magnet;
				pos = { r,c };
			}
		}
	}
	return;
};

void Output() {
	println("{} {}", pos.first, pos.second);
	if (mnMagnet) {
		println("{}", mnMagnet);
	}
	return;
};
