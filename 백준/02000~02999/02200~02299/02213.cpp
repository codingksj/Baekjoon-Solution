#include<bits/stdc++.h>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
	constexpr string_view SEPS = " \n";
	constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
	constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f;
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 1E+5;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void DFS(int v, bool isUsed);
void Output();

V1<int> G[MAX];
int dp[2][MAX];
V1<int> route;
int A[MAX];
int order[MAX];
int par[MAX];
bool visChk[MAX];
int N, u, v, cnt;

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

	for (int i : Rng(0, N)) {
		cin >> A[i];
	}
	for (int i : Rng(0, N - 1)) {
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}
	return true;
};

void Solve() {
	queue<int> q;
	q.push(0);
	visChk[0] = true;
	while (!q.empty()) {
		int v = q.front(); q.pop();
		order[cnt++] = v;
		for (int nv : G[v]) {
			if (!visChk[nv]) {
				visChk[nv] = true;
				par[nv] = v;
				q.push(nv);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		dp[1][i] = A[i];
		dp[0][i] = 0;
	}
	for (int i = N - 1; i > 0; i--) {
		int v = order[i];
		int p = par[v];
		dp[1][p] += dp[0][v];
		dp[0][p] += max(dp[0][v], dp[1][v]);
	}
	DFS(0, dp[1][0] > dp[0][0]);
	ranges::sort(route);
};

void DFS(int v, bool isUsed) {
	if (isUsed) {
		route.push_back(v + 1);
	}
	for (int nv : G[v]) {
		if (nv == par[v]) {
			continue;
		}
		if (isUsed) {
			DFS(nv, false);
		}
		else {
			DFS(nv, dp[1][nv] > dp[0][nv]);
		}
	}
};

void Output() {
	println("{}", max(dp[0][0], dp[1][0]));
	for (int v : route) {
		print("{}{}", v, SEPS[v == route.back()]);
	}
	return;
};
