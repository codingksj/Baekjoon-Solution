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
	constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 100;
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
int Find(int v);
bool Union(int u, int v);
void Output();

int par[MAX];
int deg[MAX];
bool visChk[MAX];
int TC, N, K;
int u, v, w;
bool isMike;

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
	return;
};

bool Input() {
	cin >> N >> K;

	return true;
};

void Solve() {
	memset(deg, 0, sizeof(deg));
	iota(par, par + N, 0);
	memset(visChk, false, sizeof(visChk));
	isMike = true;
	for (int i : Rng(0, K)) {
		cin >> u >> v >> w;
		Union(u, v);
		deg[u] += w;
		deg[v] += w;
		visChk[u] = true;
		visChk[v] = true;
	}
	int odd = 0;
	int p = -1;
	for (int i : Rng(0, N)) {
		if (visChk[i]) {
			odd += (deg[i] & 1);
			if (p == -1) {
				p = Find(i);
			}
			else if (p != Find(i)){
				isMike = false;
				return;
			}
		}
	}
	isMike = !odd || (odd == 2);
	return;
}

int Find(int v) {
	return v == par[v] ? v : par[v] = Find(par[v]);
}

bool Union(int u, int v) {
	u = Find(u), v = Find(v);
	if (u == v) {
		return false;
	}
	if (u < v) {
		swap(u, v);
	}
	par[u] = v;
	return true;
}

void Output() {
	println("{}", isMike ? "yes" : "no");
	return;
};
