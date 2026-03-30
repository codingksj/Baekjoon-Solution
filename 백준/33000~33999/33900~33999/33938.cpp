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
	constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f;
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 1E+3;
	constexpr auto Rng = views::iota;
	constexpr auto Rev = views::reverse;
	constexpr auto Split = views::split;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

int P[2];
int N, M, res;

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
	cin >> N >> M;

	for (int i : Rng(0, N)) {
		cin >> P[i];
	}

	return true;
};

void Solve() {
	if (N == 0) {
		res = M ? -1 : 0;
		return;
	}
	if (N == 1){
		if (P[0]) {
			res = M % P[0] ? -1 : max(-1, M / P[0]);
		}
		else {
			res = M ? -1 : 0;
		}
		return;
	}
	int mnCnt = INF;
	for (int i : Rng(0, MAX + 1)) {
		for (int j : Rng(0, MAX + 1)) {
			int cnt = i + j;
			int n = P[0] * i + P[1] * j;
			if (cnt < mnCnt && n == M) {
				mnCnt = cnt;
			}
		}
	}
	res = mnCnt == INF ? -1 : mnCnt;
	return;
};

void Output() {
	println("{}", res);
	return;
};
