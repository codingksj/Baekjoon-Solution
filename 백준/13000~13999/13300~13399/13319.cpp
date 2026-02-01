#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
template<typename T> using V1 = vector<T>; 
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V2<V1<T>>;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

constexpr auto Rng = views::iota;
constexpr auto Step = views::stride;

const string SEPS = " \n";
const int MAX = 200'000;

LL N, M;
bool isPrimes[MAX + 1];

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
	memset(isPrimes, true, sizeof(isPrimes));
	for (int n = 2; n * n <= MAX; n++) {
		if (isPrimes[n]) {
			for (int p = n * n; p <= MAX; p += n) {
				isPrimes[p] = false;
			}
		}
	}
	return;
};

bool Input() {
	return true;
};

void Solve() {
	LL st = 500 / 6 + 1;
	LL ed = 10001;
	for (LL m : Rng(st, ed)) {
		LL n1 = 6 * m + 1;
		LL n2 = 12 * m + 1;
		LL n3 = 18 * m + 1;
		if (isPrimes[n1] && isPrimes[n2] && isPrimes[n3]) {
			N = n1 * n2 * n3;
			M = n1;
			return;
		}
	}
}

void Output() {
	println("{} {}", N, M);
}
