#include<bits/stdc++.h>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
using Ti3 = tuple<int, int, int>;
using Bitset = array<ULL, 1563>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
	constexpr string_view SEPS = " \n";
	constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
	constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 1E+6;
	constexpr int DIGITS = 10, ALPHABETS = 26;
	constexpr auto Rng = views::iota;
	constexpr auto Rev = views::reverse;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

int tree[2 * bit_ceil(MAX)];
int Q, sz = bit_ceil(MAX);

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
	cin >> Q;

	return true;
};

void Solve() {
	int total = 0;
	int q, a, b;
	auto Update = [&total](int i, int diff) {
		tree[i += sz] += diff;
		total += diff;
		for (i >>= 1; i > 0; i >>= 1) {
			tree[i] = tree[i << 1] + tree[i << 1 | 1];
		}
	};
	auto Query = [&Update](int n) {
		int idx = 1;
		while (idx < sz) {
			int l = idx << 1;
			if (tree[l] >= n) {
				idx = l;
			}
			else {
				n -= tree[l];
				idx = l + 1;
			}
		}
		Update(idx - sz, -1);
		return idx - sz;
	};
	while (Q--) {
		cin >> q >> a;
		if (q == 1) {
			println("{}", Query(a));
		}
		else {
			cin >> b;
			Update(a, b);
		}
	}
	return;
};

void Output() {
	return;
};
