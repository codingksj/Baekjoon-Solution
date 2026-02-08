#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<numbers>
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
	constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 1 << 4;
	constexpr int DIGITS = 10, ALPHABETS = 26;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void DFS(int r, int usedC, int diagM, int diagA);
void Output();

// ---------- 전역 변수 ----------
int N, cnt;

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

	return true;
};

void Solve() {
	DFS(0, 0, 0, 0);
	return;
};

void DFS(int r, int usedC, int diagM, int diagA) {
	if (r == N) {
		cnt++;
		return;
	}
	for (int c = 0; c < N; c++) {
		int b1 = 1 << c;
		int b2 = 1 << (r - c + N);
		int b3 = 1 << (r + c);
		if (!((usedC & b1) || (diagM & b2) || (diagA & b3))) {
			DFS(r + 1, usedC | b1, diagM | b2, diagA | b3);
		}
	}
};

void Output() {
	println("{}", cnt);
	return;
};
