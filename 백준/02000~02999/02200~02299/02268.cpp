#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

namespace CONSTS {
	constexpr int MOD = 1E+9 + 7, INF = 0x3f3f3f3f, DIGITS = 10, MAX = 5'000;
	constexpr string_view SEPS = " \n";
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}

using namespace CONSTS;

using LL = long long;
using Pii = pair<int, int>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Update(int i, LL val);
LL Query(int l, int r);
void Output();

V1<LL> tree;
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
	cin >> N >> Q;

	return true;
};

void Solve() {
	sz = bit_ceil((size_t)(N));
	tree = V1<LL>(2 * sz);

	while (Q--) {
		cin >> q;
		if (q == 0) {
			cin >> l >> r;
			if (l > r) {
				swap(l, r);
			}
			println("{}", Query(l - 1, r));
		}
		else {
			cin >> i >> val;
			Update(i - 1, val);
		}
	}
	return;
}

void Update(int i, LL val) {
	for (tree[i += sz] = val; i > 1; ) {
		i >>= 1;
		tree[i] = tree[i << 1] + tree[i << 1 | 1];
	}
};

LL Query(int l, int r) {
	LL res = 0;
	for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
		(l & 1) && (res += tree[l++]);
		(r & 1) && (res += tree[--r]);
	}
	return res;
}

void Output() {
	return;
}
