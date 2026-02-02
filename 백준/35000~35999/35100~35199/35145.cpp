#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

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

constexpr auto Rng = views::iota;
constexpr auto Step = views::stride;

const string SEPS = " \n";
const LL MOD = 1E+9 + 7;
const int DIGITS = 10;
const int MAX = 1E+3;

V1<Pii> dt;
char A[MAX + 1][MAX + 1];
string line;
int R, C, rect;

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
	for (int dr : Rng(0, DIGITS + 1)) {
		for (int dc : Rng(0, DIGITS + 1)) {
			if ((dr + 1) * (dc + 1) <= DIGITS) {
				dt.push_back(Pii(dr, dc));
			}
		}
	}
	return;
};

bool Input() {
	cin >> R >> C;

	for (int r : Rng(0, R)) {
		cin >> line;
		for (int c : Rng(0, C)) {
			A[r][c] = line[c] - '0';
		}
	}

	return true;
};

void Solve() {
	auto FindRect = [&](int r, int c) {
		int cnt = 0;
		for (const auto& [dr, dc] : dt) {
			if (r + dr >= R || c + dc >= C) {
				continue;
			}
			int chk = 0;
			bool isRect = true;
			for (int i : Rng(r, r + dr + 1)) {
				for (int j : Rng(c, c + dc + 1)) {
					int bit = 1 << A[i][j];
					if (chk & bit) {
						isRect = false;
						break;
					}
					chk |= bit;
				}
				if (!isRect) {
					break;
				}
			}
			cnt += isRect;
		}
		return cnt;
	};
	for (int r : Rng(0, R)) {
		for (int c : Rng(0, C)) {
			rect += FindRect(r, c);
		}
	}
	return;
}

void Output() {
	println("{}", rect);
}
