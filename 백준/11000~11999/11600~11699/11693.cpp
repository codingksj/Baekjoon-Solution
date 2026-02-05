#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
	constexpr int MOD = 1E+9 + 7, INF = 0x3f3f3f3f, DIGITS = 10, MAX = 1 << 15;
	constexpr string_view SEPS = " \n";
	constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}

using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

V1<PLL> factors;
LL n, m, res = 1;

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
	cin >> n >> m;
	return true;
};

void Solve() {
	auto PowMod = [](LL b, LL e) {
		LL res = 1;
		for (b %= MOD; e; e >>= 1, b = b * b % MOD) {
			if (e & 1) {
				res = res * b % MOD;
			}
		}
		return res;
	};
	for (LL p : Rng(2, MAX)) {
		int cnt = 0;
		while (!(n % p)) {
			cnt++;
			n /= p;
		}
		if (cnt) {
			factors.push_back({ p, cnt * m });
		}
	}
	if (n > 1) {
		factors.push_back({ n, m });
	}
	for (const auto& [p, e] : factors) {
		LL head = (PowMod(p, e + 1) + MOD - 1) % MOD;
		LL body = PowMod(p - 1, MOD - 2);
		res = res * (head * body % MOD) % MOD;
	}
	return;
}

void Output() {
	println("{}", res);
	return;
}
