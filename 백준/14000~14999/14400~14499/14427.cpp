#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using Pii = pair<int, int>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
	constexpr int MOD = 1E+9 + 7, INF = 0x3f3f3f3f, DIGITS = 10, MAX = 5'000;
	constexpr string_view SEPS = " \n";
	constexpr Pii INIT = Pii(INF, INF);
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}

using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Update(int i, LL val);
LL Query(int l, int r);
void Output();

V1<Pii> tree;
LL val; 
int N, Q, q, l, r, i, sz;

int main() {
	FastIO();
	SetUp();

	Input();
	Solve();
	Output();

	return 0;
}

void FastIO() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
};

void SetUp() {
	return;
};

bool Input() {
	cin >> N;

	sz = bit_ceil((size_t)(N));
	tree = V1<Pii>(2 * sz, INIT);

	for (int i : Rng(0, N)) {
		auto& [val, idx] = tree[sz + i];
		cin >> val;
		idx = i;
	}
	cin >> Q;

	return true;
};

void Solve() {
	for (int i = sz - 1; i > 0; --i) {
		tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
	}
	while (Q--) {
		cin >> q;
		if (q == 2) {
			println("{}", Query(0, sz));
		}
		else {
			cin >> i >> val;
			Update(i - 1, val);
		}
	}
	return;
}

void Update(int i, LL val) {
	int idx = i;
	for (tree[i += sz] = Pii(val, idx); i > 1; ) {
		i >>= 1;
		tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
	}
};

LL Query(int l, int r) {
	Pii res = INIT;
	for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
		if (l & 1) {
			res = min(res, tree[l++]);
		}
		if (r & 1) {
			res = min(res, tree[--r]);
		}
	}
	return res.second + 1;
}

void Output() {
	return;
}
