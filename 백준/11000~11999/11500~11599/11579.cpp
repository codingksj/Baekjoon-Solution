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
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 500, LIMIT = 2E+9;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

int A[MAX][MAX];
int C[MAX];
LL mv;
int TC, N;

int main() {
	FastIO();
	SetUp();

	cin >> TC;

	while (TC--) {
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
	return;
};

bool Input() {
	cin >> N;

	for (int r : Rng(0, N)) {
		for (int c : Rng(0, N)) {
			cin >> A[r][c];
		}
	}
	for (int i : Rng(0, N)) {
		cin >> C[i];
	}
	return true;
};

void Solve() {
	mv = 0;
	for (int r : Rng(0, N)) {
		LL x = C[r];
		if (x < 0) {
			mv = LIMIT + 1;
			return;
		}
		for (int c : Rng(0, N)) {
			C[c] -= x * A[r][c];
		}
		mv += x;
		if (x > LIMIT) {
			return;
		}
	}
};

void Output() {
	if (mv <= LIMIT) {
		println("1 {}", mv);
	}
	else {
		println("0");
	}
	return;
};
