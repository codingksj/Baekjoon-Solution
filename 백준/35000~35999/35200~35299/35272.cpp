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
	constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f;
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 21;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

int C[MAX][MAX];
int N;
double p, q, E;

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
	for (int i : Rng(0, MAX)) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
	return;
};

bool Input() {
	cin >> N >> p >> q;

	return true;
};

void Solve() {
	double powP[MAX] = { 1 };
	double powNotP[MAX] = { 1 };
	double powQ[MAX] = { 1 };
	double powNotQ[MAX] = { 1 };
	for (int i : Rng(1, MAX)) {
		powP[i] = powP[i - 1] * p;
		powNotP[i] = powNotP[i - 1] * (1.0 - p);
		powQ[i] = powQ[i - 1] * q;
		powNotQ[i] = powNotQ[i - 1] * (1.0 - q);
	}
	auto GetProb = [](int n, int r, double* p, double* np) {
		return C[n][r] * p[r] * np[n - r];
	};
	for (int x : Rng(1, N + 1)) {
		E += x * GetProb(N, x, powQ, powNotQ);
	}
	for (int y : Rng(1, N + 1)) {
		double curE = 0;
		for (int total : Rng(1, N + 1)) {
			double prob = 0;
			for (int i = 0; i <= min(y, total); i++) {
				prob += GetProb(y, i, powP, powNotP) * GetProb(N, total - i, powQ, powNotQ);
			}
			curE += prob * total;
		}
		E = max(E, curE);
	}
	return;
};

void Output() {
	println("{}", E);
	return;
};
