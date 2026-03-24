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
	constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 1E+5;
	constexpr int DIGITS = 10, ALPHABETS = 26;
	constexpr auto Rng = views::iota;
	constexpr auto Rev = views::reverse;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void DFS(int v, int d, LL w);
void Output();

int par[bit_width(MAX) + 1][MAX + 1];
V1<PLL> G[MAX + 1];
LL W[MAX + 1];
int D[MAX + 1];
bool visChk[MAX + 1];
int N, Q, u, v, w, q, k;

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
	cin >> N;

	for (int i : Rng(0, N - 1)) {
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	cin >> Q;

	return true;
};

void Solve() {
	DFS(1, 0, 0);
	int mxLv = bit_width((ULL)N);
	for (int lv : Rng(1, mxLv)) {
		for (int i = 1; i <= N; i++) {
			par[lv][i] = par[lv - 1][par[lv - 1][i]];
		}
	}
	auto GetLCA = [mxLv](int u, int v) {
		if (D[u] > D[v]) {
			swap(u, v);
		}
		int diff = D[v] - D[u];
		for (int lv = 0; diff; lv++, diff >>= 1) {
			(diff & 1) && (v = par[lv][v]);
		}
		if (u == v) {
			return u;
		}
		for (int lv = mxLv - 1; lv >= 0; lv--) {
			if (par[lv][u] != par[lv][v]) {
				u = par[lv][u];
				v = par[lv][v];
			}
		}
		return par[0][u];
	};
	auto FindNth = [](int v, int n) {
		for (int lv = 0; n; lv++, n >>= 1) {
			if (n & 1) {
				v = par[lv][v];
			}
		}
		return v;
	};
	while (Q--) {
		cin >> q >> u >> v;
		int lca = GetLCA(u, v);
		if (q == 1) {
			LL cost = W[u] + W[v] - 2 * W[lca];
			println("{}", cost);
		}
		else {
			cin >> k;
			int ruCnt = D[u] - D[lca] + 1;
			int rvCnt = D[v] - D[lca] + 1;
			int totCnt = ruCnt + rvCnt - 1;
			int kv = (k <= ruCnt) ? FindNth(u, k - 1) : FindNth(v, totCnt - k);
			println("{}", kv);
		}
	}
	return;
};

void DFS(int v, int d, LL w){
	visChk[v] = true;
	D[v] = d;
	W[v] = w;
	for (const auto& [nv, cost] : G[v]) {
		if (!visChk[nv]) {
			par[0][nv] = v;
			DFS(nv, d + 1, w + cost);
		}
	}
};

void Output() {
	return;
};
