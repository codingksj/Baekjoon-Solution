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
	constexpr string_view SEPS = " \n";
	constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
	constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 500;
	constexpr int DIGITS = 10;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}

using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

LL P;
int S[MAX];
int N, M;
bool canWin = true;

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
	cin >> N >> M >> P;

	return true;
};

void Solve() {
	for (int i : Rng(0, N)) {
		int itemCnt = 0;
		for (int j : Rng(0, M)) {
			cin >> S[j];
		}
		ranges::sort(S | views::take(M));
		for (int j : Rng(0, M)) {
			if (S[j] == -1) {
				itemCnt++;
			}
			else {
				if (P >= S[j]) {
					P += S[j];
					continue;
				}
				if (itemCnt && (P << 1 >= S[j])) {
					P <<= 1;
					P += S[j];
					itemCnt--;
					continue;
				}
				canWin = false;
				return;
			}
		}
		while (itemCnt--) {
			P <<= 1;
		}
	}
	return;
}

void Output() {
	println("{}", (int)canWin);
	return;
}
