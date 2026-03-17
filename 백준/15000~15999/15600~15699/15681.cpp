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
int DFS(int v);
void Output();

V1<int> G[MAX];
int sz[MAX];
int visChk[MAX];
int N, R, Q, v1, v2;

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
	cin >> N >> R >> Q;

	for (int i : Rng(0, N - 1)) {
		cin >> v1 >> v2;
		G[--v1].push_back(--v2);
		G[v2].push_back(v1);
	}

	return true;
};

void Solve() {
	fill(sz, sz + N, 1);
	sz[R - 1] = DFS(R - 1);
	while (Q--) {
		cin >> v1;
		println("{}", sz[--v1]);
	}
};

int DFS(int v) {
	visChk[v] = true;
	for (int nv : G[v]) {
		if (!visChk[nv]) {
			sz[v] += DFS(nv);
		}
	}
	return sz[v];
};

void Output() {
	return;
};
