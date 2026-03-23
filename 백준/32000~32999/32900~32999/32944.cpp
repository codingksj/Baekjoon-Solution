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
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 3E+5;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

int N, M, K, cnt;
bool isExist;

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
	cin >> N >> M >> K;

	return true;
};

void Solve() {
	isExist = N != M;
	return;
};

void Output() {
	if (!isExist) {
		println("-1");
	}
	else {
		for (int i : Rng(0, K - 1)) {
			print("{}{}", i + 1, SEPS[++cnt == N]);
		}
		for (int i : Rng(0, N - M)) {
			print("{}{}", N - i, SEPS[++cnt == N]);
		}
		for (int i : Rng(0, M - (K - 1))) {
			print("{}{}", K + i, SEPS[++cnt == N]);
		}
	}
	return;
};
