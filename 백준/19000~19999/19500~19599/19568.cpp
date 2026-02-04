#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

namespace CONSTS {
	constexpr int MOD = 1E+9 + 7, INF = 0x3f3f3f3f, DIGITS = 10, MAX = 30;
	constexpr string_view SEPS = " \n";
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}

using namespace CONSTS;

using LL = long long;
using Pii = pair<int, int>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

int A[MAX][MAX];
int N;

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
	cin >> N;

	return true;
};

void Solve() {
	for (int c : Rng(0, 14)) {
		A[14][c] = 1;
		A[c][14] = 15;
		A[14][15 + c] = 225;
		A[15 + c][14] = 3375;
	}
	return;
}

void Output() {
	for (int r : Rng(0, MAX)) {
		for (int c : Rng(0, MAX)) {
			print("{}{}", A[r][c], SEPS[c == MAX - 1]);
		}
	}
	return;
}
