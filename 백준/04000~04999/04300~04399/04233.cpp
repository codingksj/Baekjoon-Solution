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
const double EPS = 0.01;

LL A, P;
bool isFakePrime;

int main() {
	FastIO();
	SetUp();

	while (Input()) {
		Solve();
		Output();
	}

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
	cin >> A >> P;

	return A || P;
};

void Solve() {
	isFakePrime = false;
	if (A > P) {
		swap(A, P);
	}
	auto PowMod = [&](LL b, LL e, const LL P) {
		LL res = 1;
		b %= P;
		for (; e; e >>= 1, b = b * b % P) {
			if (e & 1) {
				res = res * b % P;
			}
		}
		return res;
	};
	auto ChkPrime = [&](LL n) {
		for (LL b = 2; b * b <= n; b++) {
			if (!(n % b)) {
				return false;
			}
		}
		return true;
	};
	if (ChkPrime(P)) {
		return;
	}
	isFakePrime = (PowMod(A, P, P) == A);
}

void Output() {
	println("{}", isFakePrime ? "yes" : "no");
}
