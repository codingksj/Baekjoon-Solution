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

LL B, P, N, L;

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
	return (bool)(cin >> P >> B >> N);
};

void Solve() {
	unordered_map<LL, LL> mp;
	LL m = ceil(sqrt(P - 1));
	L = -1;
	auto PowMod = [](LL base, LL exp, const LL MOD) {
		LL res = 1;
		base %= MOD;
		for (; exp; exp >>= 1, base = base * base % MOD) {
			if (exp & 1) {
				res = res * base % MOD;
			}
		}
		return res;
	};
	LL res = 1;
	for (LL i : Rng(0, m)) {
		if (!mp.count(res)) {
			mp[res] = i;
		}
		res = res * B % P;
	}
	LL bm = PowMod(B, m, P);
	LL invBm = PowMod(bm, P - 2, P);
	LL target = N;
	for (LL i : Rng(0, m + 1)) {
		if (mp.count(target)) {
			L = i * m + mp[target];
			return;
		}
		target = target * invBm % P;
	}
}

void Output() {
	if (L == -1) {
		println("no solution");
		return;
	}
	println("{}", L);
}
