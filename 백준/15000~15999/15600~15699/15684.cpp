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
	constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX_H = 1 << 5, MAX_N = 10;
	constexpr int DIGITS = 10, ALPHABETS = 26;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void DFS(int depth, int idx, const int MAX_DEPTH);
bool Simulate();
void Output();

// ---------- 전역 변수 ----------
V1<Pii> ladders;
bool isLadder[MAX_H + 1][MAX_N + 1];
int dests[MAX_N + 1];
int N, M, H, v, h, sz, cnt = INF;

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
	cin >> N >> M >> H;

	while(M--) {
		cin >> h >> v;
		isLadder[h][v] = true;
	}
	return true;
};

void Solve() {
	for (int h = 1; h <= H; h++) {
		for(int v = 1; v < N; v++) {
			if (!isLadder[h][v] && !isLadder[h][v - 1] && !isLadder[h][v + 1]) {
				ladders.emplace_back(h, v);
			}
		}
	}
	sz = ladders.size();
	for (int limit = 0; limit <= 3; limit++) {
		DFS(0, 0, limit);
		if (cnt != INF) {
			break;
		}
	}
	return;
};

void DFS(int depth, int idx, const int MAX_DEPTH) {
	if (cnt != INF) {
		return;
	}
	if (depth == MAX_DEPTH) {
		if (Simulate()) {
			cnt = depth;
		}
		return;
	}
	for (int i = idx; i < sz; i++) {
		auto [h, v] = ladders[i];
		if (isLadder[h][v - 1] || isLadder[h][v] || isLadder[h][v + 1]) {
			continue;
		}
		isLadder[h][v] = true;
		DFS(depth + 1, i + 1, MAX_DEPTH);
		isLadder[h][v] = false;
		if (cnt != INF) {
			return;
		}
	}
};

bool Simulate() {
	iota(dests + 1, dests + N + 1, 1);
	for(int n = 1; n <= N; n++) {
		int cur = n;
		for(int h = 1; h <= H; h++) {
			if (isLadder[h][cur - 1]) {
				cur--;
			}
			else if (isLadder[h][cur]) {
				cur++;
			}
		}
		if(cur != n) {
			return false;
		}
	}
	return true;
};

void Output() {
	println("{}", cnt == INF ? -1 : cnt);
	return;
};
