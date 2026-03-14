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
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 50;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

LL S[MAX];
LL U;
int TC, N, K, b, res;

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
		cin >> K;
		LL s = 0;
		for (int j : Rng(0, K)) {
			cin >> b;
			s |= (1LL << b);
		}
		S[i] = s;
		U |= S[i];
	}

	return true;
};

void Solve() {
	res = 0;
	for (int b = 1; b <= MAX; b++) {
		LL s = 0;
		LL t = 1LL << b;
		if (!(U & t)) {
			continue;
		}
		for (int i : Rng(0, N)) {
			if (!(S[i] & t)) {
				s |= S[i];
			}
		}
		res = max(res, popcount((ULL)s));
	}
	U = 0;
};

void Output() {
	println("{}", res);
	return;
};
