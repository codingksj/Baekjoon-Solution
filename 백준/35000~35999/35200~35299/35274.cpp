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
	constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 1E+5;
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

LL A[MAX];
LL N, M, L, X = -1;

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
	cin >> N >> M >> L;

	for (int i : Rng(0, N)) {
		cin >> A[i];
	}

	return true;
};

void Solve() {
	auto CanClean = [](LL X) {
		LL limit = M;
		LL snow = 0;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			snow += A[i];
			cnt++;
			if (snow >= X) {
				LL used = snow / X;
				limit -= used;
				snow %= X;
				cnt = snow > 0;
			}
			if (cnt == L) {
				limit -= (snow > 0);
				snow = 0;
				cnt = 0;
			}
		}
		if (snow) {
			limit--;
		}
		return limit >= 0;
	};
	LL l = 1;
	LL r = 1E+15;
	while (l <= r) {
		LL m = (l + r) / 2;
		if (CanClean(m)) {
			X = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	return;
};

void Output() {
	println("{}", X);
	return;
};
