#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
using ui64 = unsigned long long;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
	constexpr string_view SEPS = " \n";
	constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
	constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 1E+6;
	constexpr int DIGITS = 10;
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
V1<int> primes;
int N, n1, n2, n3, n4;

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
	isPrimes.set();
	isPrimes[0] = isPrimes[1] = false;
	for (int i = 2; i * i <= MAX; i++) {
		if (isPrimes[i]) {
			for (int p = i * i; p <= MAX; p += i) {
				isPrimes[p] = false;
			}
		}
	}
	primes.push_back(2);
	for (int p : Rng(3, MAX + 1) | Step(2)) {
		if (isPrimes[p]) {
			primes.push_back(p);
		}
	}
	return;
};

bool Input() {
	cin >> N;

	return true;
};

void Solve() {
	if (N < 8) {
		return;
	}
	n1 = 2;
	n2 = 2 + (N & 1);
	for (int p : primes) {
		n3 = p;
		n4 = N - (n1 + n2 + n3);
		if (n4 >= 2 && isPrimes[n4]) {
			return;
		}
	}
	return;
}

void Output() {
	if (!n1) {
		println("{}", -1);
	}
	else {
		println("{} {} {} {}", n1, n2, n3, n4);
	}
	return;
}
