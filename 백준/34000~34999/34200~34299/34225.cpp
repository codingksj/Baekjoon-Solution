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

Pii A[MAX + 1];
int N, cnt;

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

	for (int i : Rng(1, N + 1)) {
		auto& [a, idx] = A[i];
		cin >> a;
		idx = i;
	}

	return true;
};

void Solve() {
	sort(A + 1, A + N + 1, greater<>());
	LL mxScore = -1;
	LL pfSum = 0;
	LL curScore = 0;
	int mx = A[1].first;
	for (int i : Rng(1, N + 1)) {
		LL cur = A[i].first;
		pfSum += cur;
		curScore = pfSum + mx + cur;
		if (curScore > mxScore) {
			mxScore = curScore;
			cnt = i;
		}
	}
	return;
}

void Output() {
	println("{}", cnt);
	for (int i : Rng(1, cnt + 1)) {
		print("{}{}", A[i].second, SEPS[i == cnt]);
	}
	return;
};
