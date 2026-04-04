#include<bits/stdc++.h>
#include<ranges>
#include<print>
#include<random>

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
	constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f;
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 1E+6;
	constexpr auto Rng = views::iota;
	constexpr auto Rev = views::reverse;
	constexpr auto Split = views::split;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

random_device rd;
mt19937 gen(rd());
string T, P;
ULL w[2][ALPHABETS];
int res;

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
	set<ULL> used;
	for (int t : Rng(0, 2)) {
		for (int i = 0; i < ALPHABETS; i++) {
			ULL val = 0;
			do {
				val = gen();
			} while (!val || used.count(val));
			w[t][i] = val;
			used.insert(val);
		}
	}
	return;
};

bool Input() {
	getline(cin, T);
	getline(cin, P);

	return true;
};

void Solve() {
	if (T.size() < P.size()) {
		swap(T, P);
	}
	int tN = T.size();
	int pN = P.size();

	for (res = pN; res; res--) {
		set<pair<ULL, ULL>> lookUp;
		ULL h1 = 0, h2 = 0;
		for (int i = 0; i < res - 1; i++) {
			h1 += w[0][T[i] - 'a'];
			h2 += w[1][T[i] - 'a'];
		}
		for (int i = res - 1; i < tN; i++) {
			h1 += w[0][T[i] - 'a'];
			h2 += w[1][T[i] - 'a'];
			lookUp.insert({ h1, h2 });
			h1 -= w[0][T[i - (res - 1)] - 'a'];
			h2 -= w[1][T[i - (res - 1)] - 'a'];
		}
		ULL p1 = 0, p2 = 0;
		for (int i = 0; i < res - 1; i++) {
			p1 += w[0][P[i] - 'a'];
			p2 += w[1][P[i] - 'a'];
		}
		bool found = false;
		for (int i = res - 1; i < pN; i++) {
			p1 += w[0][P[i] - 'a'];
			p2 += w[1][P[i] - 'a'];
			found |= lookUp.count({ p1, p2 });
			p1 -= w[0][P[i - (res - 1)] - 'a'];
			p2 -= w[1][P[i - (res - 1)] - 'a'];
		}
		if (found) {
			return;
		}
	}
	return;
};

void Output() {
	println("{}", res);
	return;
};
