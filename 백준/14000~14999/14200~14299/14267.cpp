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
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 1E+5;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

V1<int> G[MAX];
LL good[MAX];
LL lazy[MAX];
int N, M, v, i, w;

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
		cin >> v;
		if (v != -1) {
			G[--v].push_back(i);
		}
	}

	return true;
};

void Solve() {
	auto Good = [](int v, LL w, auto&& self) -> void{
		LL sum = w + lazy[v];
		good[v] += sum;
		for (int nv : G[v]) {
			self(nv, sum, self);
		}
	};
	while (M--) {
		cin >> i >> w;
		lazy[--i] += w;
	}
	Good(0, 0, Good);
	return;
};

void Output() {
	for (int i : Rng(0, N)) {
		print("{}{}", good[i], SEPS[i == N - 1]);
	}
	return;
};
