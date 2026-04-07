#include <bits/stdc++.h>
#include <ranges>
#include <print>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
using Ti3 = tuple<int, int, int>;

template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
	constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
	constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 2E+5;
    constexpr int DIGITS = 10, ALPHABETS = 26;
    constexpr auto Rng = views::iota;
    constexpr auto Rev = views::reverse;
	constexpr auto Take = views::take;
    constexpr auto Split = views::split;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

bool isPrimes[MAX + 2];
int S[MAX + 2];
int TC, N;

int main() {
	FastIO();
	SetUp();

	cin >> TC;

	while (TC--) {
		Input();
		Solve();
		Output();
	}

	return 0;
}

void FastIO() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	return;
};

void SetUp() {
	memset(isPrimes, true, sizeof(isPrimes));
	isPrimes[0] = isPrimes[1] = false;
	for (int n = 4; n <= MAX; n += 2) {
		isPrimes[n] = false;
	}
	for (int n = 3; n * n <= MAX; n += 2) {
		if (isPrimes[n]) {
			for (int p = n * n; p <= MAX; p += 2 * n) {
				isPrimes[p] = false;
			}
		}
	}
	auto IsSpecial = [](int n) {
		if (!isPrimes[n + 1]) {
			return false;
		}
		for (int b = 10; b <= n; b *= 10) {
			int p = (n / b) * (n % b) + 1;
			if (!isPrimes[p]) {
				return false;
			}
		};
		return true;
	};
	for (int n : Rng(1, MAX + 1)) {
		S[n] = S[n - 1] + IsSpecial(n);
	}
	return;
};

bool Input() {
	cin >> N;

	return true;
};

void Solve() {
	return;
}

void Output() {
	println("{}", S[N]);
	return;
};
