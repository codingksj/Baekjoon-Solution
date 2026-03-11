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
	constexpr int DIGITS = 10, ALPHABETS = 26, PRIMES = 1E+6, MAX = 15E+6;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

bitset<MAX + 1> isPrimes;
int primes[PRIMES];
ULL N, M, cnt, res = 1;

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
	isPrimes.set();
	for (LL n = 4; n <= MAX; n += 2) {
		isPrimes[n] = false;
	}
	primes[cnt++] = 2;
	return;
};

bool Input() {
	cin >> N >> M;

	return true;
};

void Solve() {
	if (N > M) {
		swap(N, M);
	}
	auto PowMod = [](ULL b, ULL e) {
		ULL res = 1;
		for (; e > 0; e >>= 1, b = (b * b) % MOD) {
			if (e & 1) {
				res = res * b % MOD;
			}
		}
		return res;
	};
	ULL pCnt = 0, p = 2;
	for (ULL n = p; n <= N; n <<= 1) {
		pCnt += (N / n) * (M / n);
	}
	res = res * PowMod(2, pCnt % (MOD - 1)) % MOD;
	for (LL p = 3; p <= N; p += 2) {
		if (isPrimes[p]) {
			primes[cnt++] = p;
			ULL pCnt = 0;
			for (ULL n = p; n <= N; n *= p) {
				pCnt += (N / n) * (M / n);
				if (n * p > MAX) {
					break;
				}
			}
			res = res * PowMod(p, pCnt % (MOD - 1)) % MOD;
		}
		for (int i = 1; i < cnt; i++) {
			LL pp = primes[i];
			LL np = p * pp;
			if (np > MAX) {
				break;
			}
			isPrimes[np] = false;
			if (!(p % pp)) {
				break;
			}
		}
	}
};

void Output() {
	println("{}", res);
	return;
};
