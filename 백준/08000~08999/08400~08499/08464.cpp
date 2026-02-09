#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<numbers>
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
	constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, SQRT_MAX = 175'000;
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

// ---------- 전역 변수 ----------
V1<int> primes;
bitset<SQRT_MAX + 1> isSq, mu, signs;
LL s, e, k, N;

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
	mu[1] = 1;
	signs[1] = 0;
	for (LL i = 2; i <= SQRT_MAX; i++) {
		if (!isSq[i]) {
			primes.push_back(i);
			mu[i] = 1;
			signs[i] = 1;
		}
		for (int p : primes) {
			if (i * p > SQRT_MAX) {
				break;
			}
			isSq[i * p] = 1;
			if (i % p == 0) {
				mu[i * p] = 0;
				break;
			}
			else {
				mu[i * p] = mu[i];
				signs[i * p] = !signs[i];
			}
		}
	}
	return;
};

bool Input() {
	cin >> N;

	return true;
};

void Solve() {
	s = 1, e = max(3 * N, 100LL);

	auto F = [&](LL x) {
		LL res = 0;
		for (LL n = 1; n * n <= x; n++) {
			if (!mu[n]) {
				continue;
			}
			LL val = x / (n * n);
			res += (signs[n] ? -val : val);
		}
		return x - res;
	};

	while (s < e) {
		k = (s + e) / 2;
		F(k) < N ? s = k + 1 : e = k;
	}
	return;
};

void Output() {
	println("{}", s);
	return;
};
