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

int spf[MAX + 1];
int primes[PRIMES];
LL res = 1;
int N, M, K, cnt;

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
	primes[cnt++] = 2;
	for (int n = 2; n <= MAX; n += 2) {
		spf[n] = 2;
	}
	for (int n = 3; n <= MAX; n += 2) {
		if (!spf[n]) {
			spf[n] = n;
			primes[cnt++] = n;
		}
		for (int i = 1; i < cnt; i++) {
			int p = primes[i];
			int np = p * n;
			if (np > MAX || p > spf[n]) {
				break;
			}
			spf[np] = p;
		}
	}
	return;
};

bool Input() {
	cin >> N >> K >> M;

	return true;
};

void Solve() {
	auto PowMod = [](LL base, int exp) {
		LL res = 1;
		for (; exp > 0; exp >>= 1, base = (base * base) % M) {
			if (exp & 1) {
				res = (res * base) % M;
			}
		}
		return res;
	};
	for (int i = 0; i < cnt; i++) {
		int p = primes[i];
		int pCnt = 0;
		for (LL n = p; n <= N; n *= p) {
			pCnt += (N / n);
			if (n > N / p) {
				break;
			}
		}
		for (LL n = p; n <= K; n *= p) {
			pCnt -= (K / n);
			if (n > K / p) {
				break;
			}
		}
		for (LL n = p; n <= (N - K); n *= p) {
			pCnt -= (N - K) / n;
			if (n > (N - K) / p) {
				break;
			}
		}
		res = res * PowMod(p, pCnt) % M;
	}
};

void Output() {
	println("{}", res);
	return;
};
