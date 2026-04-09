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
	constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 2E+5;
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

V1<int> unqD;
int D[MAX];
int N, sum, sz;

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

	for (int i : Rng(0, N)) {
		cin >> D[i];
		sum += D[i];
	}

	return true;
};

void Solve() {
	for (int i : Rng(0, N)) {
		unqD.push_back(sum - D[i]);
	}
	ranges::sort(unqD);
	auto [s, e] = ranges::unique(unqD);
	unqD.erase(s, e);
	sz = unqD.size();
	return;
}

void Output() {
	println("{}", sz);
	for (int i : Rng(0, sz)) {
		print("{}{}", unqD[i], SEPS[i == sz - 1]);
	}
	return;
};
