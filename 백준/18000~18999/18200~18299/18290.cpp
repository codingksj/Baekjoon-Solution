#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
using ui64 = unsigned long long;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
	constexpr string_view SEPS = " \n";
	constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
	constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 10;
	constexpr int DIGITS = 10;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}

using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void DFS(int depth, int idx, int sum);
void Output();

int A[MAX][MAX];
bool used[MAX][MAX];
int N, M, K;
int mxSum = -INF;

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
	return;
};

bool Input() {
	cin >> N >> M >> K;

	for (int i : Rng(0, N)) {
		for (int j : Rng(0, M)) {
			cin >> A[i][j];
		}
	}

	return true;
};

void Solve() {
	DFS(0, 0, 0);
	return;
}

void DFS(int depth, int idx, int sum) {
	if (depth == K) {
		mxSum = max(mxSum, sum);
		return;
	}
	for (int i = idx; i < N * M; i++) {
		int r = i / M;
		int c = i % M;
		bool canGo = true;
		if (r > 0 && used[r - 1][c] || c > 0 && used[r][c - 1]) {
			canGo = false;
		}
		if (canGo) {
			used[r][c] = true;
			DFS(depth + 1, i + 1, sum + A[r][c]);
			used[r][c] = false;
		}
	}
};

void Output() {
	println("{}", mxSum);
	return;
}
