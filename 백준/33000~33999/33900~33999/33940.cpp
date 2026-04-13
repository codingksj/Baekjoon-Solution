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
	constexpr auto Take = views::take;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

LL res[MAX];
LL N, a, d, M, L, target;

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
	cin >> N >> a >> d >> M;

	return true;
};

void Solve() {
	auto MakeSeq = []() {
		LL diff = target - L * (L - 1) / 2;
		for (int i : Rng(0, L) | Rev) {
			LL mx = N - L + i;
			LL add = min(diff, mx - i);
			res[i] = a + (i + add) * d;
			diff -= add;
		}
	};
	for (LL k = N; k > 0; k--) {
		if (!((M - k * a) % d)) {
			target = (M - k * a) / d;
			LL mn = k * (k - 1) / 2;
			LL mx = k * (2 * N - k - 1) / 2;
			if (target >= mn && target <= mx) {
				L = k;
				MakeSeq();
				return;
			}
		}
	}
	return;
};

void Output() {
	if (!L) {
		println("-1");
		return;
	}
	println("{}", L);
	for (int i : Rng(0, L)) {
		print("{}{}", res[i], SEPS[i == L - 1]);
	}
	return;
};
