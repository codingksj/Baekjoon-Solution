#include<bits/stdc++.h>
#include<ranges>
#include<print>

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

string T, P;
int F[MAX];
int pos[MAX];
int cnt;

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
	return;
};

bool Input() {
	getline(cin, T);
	getline(cin, P);

	return true;
};

void Solve() {
	int tN = T.size();
	int pN = P.size();
	auto GetFail = [&]() {
		for (int i = 1, j = 0; i < pN; i++) {
			while (j > 0 && P[i] != P[j]) {
				j = F[j - 1];
			}
			if (P[i] == P[j]) {
				F[i] = ++j;
			}
		}
	};
	auto KMP = [&]() {
		for (int i = 0, j = 0; i < tN; i++) {
			while (j > 0 && T[i] != P[j]) {
				j = F[j - 1];
			}
			if (T[i] == P[j]) {
				if (j == pN - 1) {
					pos[cnt++] = i - pN + 2;
					j = F[j];
				}
				else {
					j++;
				}
			}
		}
	};
	GetFail();
	KMP();
	return;
};

void Output() {
	println("{}", cnt);
	for (int i = 0; i < cnt; i++) {
		print("{}{}", pos[i], SEPS[i == cnt - 1]);
	}
	return;
};
