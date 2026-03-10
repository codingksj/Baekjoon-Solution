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
	constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, PRIMES = 3E+5, MAX = 4E+6;
	constexpr int DIGITS = 10, ALPHABETS = 26;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

V1<Pii> v;
int N, Q, sz;

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

	sz = bit_ceil((ULL)N);
	v.resize(2 * sz);

	for (int i : Rng(0, N)) {
		cin >> v[i + sz].first;
	}

	cin >> Q;

	return true;
};

void Solve() {
	auto Build = [](Pii& par, const Pii& p1, const Pii& p2) {
		if (p1.first > p2.first) {
			par.first = p1.first;
			par.second = max(p1.second, p2.first);
		}
		else {
			par.first = p2.first;
			par.second = max(p2.second, p1.first);
		}
	};
	auto Merge = [](Pii& target, const Pii& other) {
		if (target.first > other.first) {
			target.second = max(target.second, other.first);
		}
		else {
			target.second = max(other.second, target.first);
			target.first = other.first;
		}
	};
	for (int i = sz - 1; i > 0; i--) {
		Build(v[i], v[i << 1], v[i << 1 | 1]);
	}
	auto Update = [&Build](int idx, int val) {
		v[idx += sz].first = val;
		for (idx >>= 1; idx > 0; idx >>= 1) {
			Build(v[idx], v[idx << 1], v[idx << 1 | 1]);
		}
	};
	auto Query = [&Merge](int l, int r){
		Pii res = { 0, 0 };
		for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
			if (l & 1) {
				Merge(res, v[l++]);
			}
			if (~r & 1) {
				Merge(res, v[r--]);
			}
		}
		return res.first + res.second;
	};
	int q, i, v, l, r;
	while (Q--) {
		cin >> q;
		if (q == 1) {
			cin >> i >> v;
			Update(--i, v);
		}
		else {
			cin >> l >> r;
			println("{}", Query(--l, --r));
		}
	}
};

void Output() {
	return;
};
