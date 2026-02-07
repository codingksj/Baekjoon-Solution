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
	constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 100;
	constexpr int DIGITS = 10, NONE = 1 << 8, UP = 1 << 9, DOWN = 1 << 10;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}

using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
bool CheckRow(int r);
bool CheckCol(int c);
void Output();

int A[MAX][MAX];
int N, L, mxRoad;

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
	cin >> N >> L;

	for (int r : Rng(0, N)) {
		for (int c : Rng(0, N)) {
			cin >> A[r][c];
		}
	}

	return true;
};

void Solve() {
	for (int r: Rng(0, N)) {
		CheckRow(r) && mxRoad++;
	}
	for (int c : Rng(0, N)) {
		CheckCol(c) && mxRoad++;
	}
	return;
}

bool CheckRow(int r) {
	bitset<MAX> isBridge;

	for (int i = 0; i < N - 1; i++) {
		if (A[r][i] == A[r][i + 1]) {
			continue;
		}
		int diff = A[r][i + 1] - A[r][i];
		if (abs(diff) > 1) {
			return false;
		}
		if (diff == 1) {
			for (int j = i; j > i - L; j--) {
				if (j < 0 || A[r][j] != A[r][i] || isBridge[j]) {
					return false;
				}
				isBridge[j] = true;
			}
		}
		if (diff == -1) {
			for (int j = i + 1; j <= i + L; j++) {
				if (j >= N || A[r][j] != A[r][i + 1] || isBridge[j]) {
					return false;
				}
				isBridge[j] = true;
			}
		}
	}
	return true;
};

bool CheckCol(int c) {
	bitset<MAX> isBridge;

	for (int i = 0; i < N - 1; i++) {
		if (A[i][c] == A[i + 1][c]) {
			continue;
		}
		int diff = A[i + 1][c] - A[i][c];
		if (abs(diff) > 1) {
			return false;
		}
		if (diff == 1) {
			for (int j = i; j > i - L; j--) {
				if (j < 0 || A[j][c] != A[i][c] || isBridge[j]) {
					return false;
				}
				isBridge[j] = true;
			}
		}
		if (diff == -1) {
			for (int j = i + 1; j <= i + L; j++) {
				if (j >= N || A[j][c] != A[i + 1][c] || isBridge[j]) {
					return false;
				}
				isBridge[j] = true;
			}
		}
	}
	return true;
};

void Output() {
	println("{}", mxRoad);
	return;
}
