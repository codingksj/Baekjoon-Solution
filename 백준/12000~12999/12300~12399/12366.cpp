#include <bits/stdc++.h>
#include <ranges>
#include <print>

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
	constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 20;
    constexpr int DIGITS = 10, ALPHABETS = 26;
    constexpr auto Rng = views::iota;
    constexpr auto Rev = views::reverse;
	constexpr auto Take = views::take;
    constexpr auto Split = views::split;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

int L[MAX];
int P[MAX];
int I[MAX];
int TC, N, tc;

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

	for (int i : Rng(0, N)) {
		cin >> L[i];
	}
	for (int i : Rng(0, N)) {
		cin >> P[i];
	}

	return true;
};

void Solve() {
	iota(I, I + N, 0);
	auto vL = L | Take(N);
	auto vP = P | Take(N);
	auto vI = I | Take(N);
	auto zipped = views::zip(vL, vP, vI);
	auto Comp = [](const auto& a, const auto& b) {
		const auto& [aL, aP, aI] = a;
		const auto& [bL, bP, bI] = b;
		return aP != bP ? aP > bP :aI < bI;
	};
	ranges::sort(zipped, Comp);
	return;
}

void Output() {
	print("Case #{}: ", ++tc);
	for (int i : Rng(0, N)) {
		print("{}{}", I[i], SEPS[i == N - 1]);
	}
	return;
};
