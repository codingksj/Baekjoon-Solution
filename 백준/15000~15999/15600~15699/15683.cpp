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
	constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 1 << 3;
	constexpr int DIGITS = 10, ALPHABETS = 26;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}
using namespace CONSTS;

enum OBJECTS { EMPTY, WALL = 6, WATCH };

struct CCTV {
	char r, c, type;
};

void FastIO();
void SetUp();
bool Input();
void Solve();
void DFS(int depth, ULL curWatch);
bool Ok(int r, int c);
void Output();

// ---------- 전역 변수 ----------
ULL cctvWatch[MAX][4];
ULL emptyArea;
CCTV cctvs[MAX];
V2<char> dir = {
	{}, {0}, {0,2}, {0,1}, {0,1,2}, {0,1,2,3}
};
char A[MAX][MAX];
int N, M, obj, cctvCnt, mnBlind = INF;

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
	cin >> N >> M;

	for (int r : Rng(0, N)) {
		for (int c : Rng(0, M)) {
			cin >> obj;
			A[r][c] = obj;
			if (obj == EMPTY) {
				emptyArea |= (1ULL << (r * M + c));
			}
			if (obj != EMPTY && obj != WALL) {
				cctvs[cctvCnt++] = { (char)r, (char)c, (char)obj };
			}
		}
	}
	return true;
};

void Solve() {
	for (int n : Rng(0, cctvCnt)) {
		auto [r, c, t] = cctvs[n];
		for (int d = 0; d < 4; d++) {
			ULL mask = 0;
			for (const auto& i : dir[t]) {
				const auto& [dr, dc] = DT4[(i + d) % 4];
				for (int nr = r + dr, nc = c + dc; Ok(nr, nc); nr += dr, nc += dc) {
					if (A[nr][nc] == WALL) {
						break;
					}
					if (A[nr][nc] == EMPTY) {
						mask |= (1ULL << (nr * M + nc));
					}
				}
			}
			cctvWatch[n][d] = mask;
		}
	}
	mnBlind = popcount(emptyArea);
	DFS(0, 0);
	return;
};

void DFS(int depth, ULL curWatch) {
	if (depth == cctvCnt) {
		int blind = popcount(emptyArea & ~curWatch);
		mnBlind = min(mnBlind, blind);
		return;
	}
	for (int i = 0; i < 4; i++) {
		DFS(depth + 1, curWatch | cctvWatch[depth][i]);
	}
};

bool Ok(int r, int c) {
	return !(r < 0 || r >= N || c < 0 || c >= M);
};

void Output() {
	println("{}", mnBlind);
	return;
};
