#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
	constexpr int MOD = 1E+9 + 7, INF = 0x3f3f3f3f, DIGITS = 10, MAX = 1'000;
	constexpr string_view SEPS = " \n";
	constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}

using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

queue<Pii> myQ1, myQ2, fireQ1, fireQ2;
bitset<MAX> visChk[MAX];
V1<string> M;
int R, C, escapeT;

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
	cin >> R >> C;

	M = V1<string>(R);

	for (int r : Rng(0, R)) {
		cin >> M[r];
		for (int c : Rng(0, C)) {
			if (M[r][c] == 'J') {
				visChk[r][c] = true;
				myQ1.emplace(r, c);
			}
			if (M[r][c] == 'F') {
				fireQ1.emplace(r, c);
			}
		}
	}
	return true;
};

void Solve() {
	auto Ok = [&](int r, int c) { return !(r < 0 || r >= R || c < 0 || c >= C); };

	for (;; escapeT++) {
		while (!fireQ1.empty()) {
			auto [r, c] = fireQ1.front(); fireQ1.pop();
			for (const auto& [dr, dc] : DT4) {
				int nr = r + dr;
				int nc = c + dc;
				if (Ok(nr, nc) && M[nr][nc] == '.') {
					M[nr][nc] = 'F';
					fireQ2.emplace(nr, nc);
				}
			}
		}
		swap(fireQ1, fireQ2);
		if (myQ1.empty()) {
			escapeT = INF;
			return;
		}
		while (!myQ1.empty()) {
			auto [r, c] = myQ1.front(); myQ1.pop();
			for (const auto& [dr, dc] : DT4) {
				int nr = r + dr;
				int nc = c + dc;
				if (!Ok(nr, nc)) {
					escapeT++;
					return;
				}
				if (!visChk[nr][nc] && M[nr][nc] == '.') {
					visChk[nr][nc] = true;
					myQ2.emplace(nr, nc);
				}
			}
		}
		swap(myQ1, myQ2);
	}
	return;
}

void Output() {
	println("{}", escapeT == INF ? "IMPOSSIBLE" : to_string(escapeT));
	return;
}
