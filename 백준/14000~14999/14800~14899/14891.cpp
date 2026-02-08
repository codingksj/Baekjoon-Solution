#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<numbers>
#include<print>

using namespace std;

using LL = long long;
using LD = long double;
using Pii = pair<int, int>;
using TLL3 = tuple<LL, LL, LL>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
	constexpr string_view SEPS = " \n";
	constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
	constexpr LD EPS = 1E-7, PI = numbers::pi;
	constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 1 << 3;
	constexpr int DIGITS = 10, ALPHABETS = 26, NONE = 0, CW = 1, CCW = -1, MASK = (1 << 8) - 1;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}

using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

// ---------- 전역 변수 ----------
string s;
int cogs[4];
int Q, N, R, score;

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
	for (int i : Rng(0, 4)) {
		cin >> s;
		int bit = 0;
		for (char ch : s) {
			cogs[i] |= ((ch - '0') << bit++);
		}
	}
	cin >> Q;
	return true;
};

void Solve() {
	auto Comp = [&](int l, int r) {
		bool bitLeft = cogs[l] & (1 << 2);
		bool bitRight = cogs[r] & (1 << 6);
		return bitLeft == bitRight;
	};
	while (Q--) {
		int dirs[4] = { 0,0,0,0 };
		cin >> N >> R;
		dirs[--N] = R;
		for (int l = N - 1; l >= 0; l--) {
			if (Comp(l, l + 1)) {
				break;
			}
			dirs[l] = -dirs[l + 1];
		}
		for (int r = N + 1; r < 4; r++) {
			if (Comp(r - 1, r)) {
				break;
			}
			dirs[r] = -dirs[r- 1];
		}
		for (int i : Rng(0, 4)) {
			if (dirs[i] == CW) {
				int bit = (cogs[i] >> (MAX - 1)) & 1;
				cogs[i] = (cogs[i] << 1) | bit;
			}
			if (dirs[i] == CCW) {
				int bit = cogs[i] & 1;
				cogs[i] = (cogs[i] >> 1) | (bit << (MAX - 1));
			}
		}
	}
	for (int i : Rng(0, 4)) {
		score += (cogs[i] & 1) << i;
	}
	return;
};

void Output() {
	println("{}", score);
	return;
};
