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
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 1E+3;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

double E[MAX];
double A[MAX + 1];
double pfA[MAX + 1];
double a;
int TC, tc, L, R, M, N;

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
	cin >> N >> M;

	for (int i : Rng(1, N + 1)) {
		cin >> a;
		A[i] = log(a);
		pfA[i] = pfA[i - 1] + A[i];
	}
	return true;
};

void Solve() {
	for(int m : Rng(0, M)) {
		cin >> L >> R;
		double D = R - L + 1;
		E[m] = exp((pfA[R + 1] - pfA[L]) / D);
	}
};

void Output() {
	println("Case #{}:", ++tc);
	for (int i : Rng(0, M)) {
		println("{}", E[i]);
	}
	return;
};
