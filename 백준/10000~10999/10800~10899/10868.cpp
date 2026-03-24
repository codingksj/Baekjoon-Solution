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
	constexpr int DIGITS = 10, ALPHABETS = 26, SHIFT = 17;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

int tree[bit_ceil(MAX) << 1];
int N, M, sz, a, b;

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

	sz = bit_ceil(ULL(N));

	for (int i : Rng(0, N)) {
		cin >> tree[i + sz];
	}
	return true;
};

void Solve() {
	for (int i = sz - 1; i > 0; i--) {
		tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
	}
	auto Query = [](int l, int r) {
		int res = INF;
		for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
			(l & 1) && (res = min(res, tree[l++]));
			(r & 1) && (res = min(res, tree[--r]));
		}
		return res;
	};
	while (M--) {
		cin >> a >> b;
		println("{}", Query(--a, b));
	}
	return;
};

void Output() {
	return;
};
