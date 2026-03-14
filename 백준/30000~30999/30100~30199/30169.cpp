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
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 100;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

V1<LL> factors;
LL X, N, res = 1;

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
	cin >> X >> N;

	return true;
};

void Solve() {
	int two = countr_zero((ULL)X);
	if (two) {
		X >>= two;
		factors.push_back(2);
	}
	for (LL p = 3; p * p <= X; p += 2) {
		int cnt = 0;
		while (!(X % p)) {
			X /= p;
			cnt++;
		}
		if (cnt) {
			factors.push_back(p);
		}
	}
	if (X > 1) {
		factors.push_back(X);
	}
	auto PowMod = [](LL b, LL e) {
		LL res = 1;
		for (; e; e >>= 1, b = b * b % MOD) {
			if (e & 1) {
				res = res * b % MOD;
			}
		}
		return res;
	};
	for (LL p : factors) {
		LL cnt = 0;
		for (LL n = p;; n *= p) {
			cnt += N / n;
			if (n > N / p) {
				break;
			}
		}
		res = res * PowMod(p, cnt) % MOD;
	}
};

void Output() {
	println("{}", res);
	return;
};
