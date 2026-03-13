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
	constexpr Pii DT8[8] = { {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1},{0,-1},{-1,-1} };
	constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f;
	constexpr int DIGITS = 10, ALPHABETS = 26, LINE = 5;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

string board[2][LINE][LINE];
int pos;

int main() {
	FastIO();
	SetUp();

	while (Input()) {
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
	for (int i : Rng(0, LINE)) {
		for (int j : Rng(0, LINE)) {
			cin >> board[0][i][j];
			if (board[0][i][j] == "Finished") {
				return false;
			}
			board[1][i][j] = board[0][i][j];
		}
	}
	return true;
};

void Solve() {
	auto Check = [](int tr, int tc) {
		board[0][tr][tc] = "X";
		board[1][tr][tc] = "O";
		for (int r : Rng(0, LINE)) {
			for (int c : Rng(0, LINE)) {
				for (const auto& [dr, dc] : DT8) {
					int er = r + 3 * dr;
					int ec = c + 3 * dc;
					if ((ULL)er < LINE && (ULL)ec < LINE) {
						int cnt1 = 0;
						int cnt2 = 0;
						for (int i = 0; i < 4; i++) {
							cnt1 += board[0][r + dr * i][c + dc * i] == "X";
							cnt2 += board[1][r + dr * i][c + dc * i] == "O";
						}
						if (cnt1 == 4 || cnt2 == 4) {
							board[0][tr][tc] = "*";
							board[1][tr][tc] = "*";
							return false;
						}
					}
				}
			}
		}
		return true;
	};
	for (int r : Rng(0, LINE)) {
		for (int c : Rng(0, LINE)) {
			if (board[0][r][c] == "*" && Check(r, c)) {
				pos = LINE * r + c + 1;
				return;
			}
		}
	}
};

void Output() {
	println("{}", pos);
	return;
};
