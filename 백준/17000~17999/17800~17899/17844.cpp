#include<bits/stdc++.h>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
using Ti3 = tuple<int, int, int>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
	constexpr string_view SEPS = " \n";
	constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
	constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, B = 129, M0 = MOD, M1 = MOD + 2;
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 2E+5;
	constexpr auto Rng = views::iota;
	constexpr auto Rev = views::reverse;
	constexpr auto Split = views::split;
	constexpr auto Take = views::take;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

PLL lookUp[MAX + 1];
LL powB[2][MAX + 1] = { {1,}, {1,} };
string s;
int mxL;

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
	for (int i = 1; i <= MAX; i++) {
		powB[0][i] = (powB[0][i - 1] * B) % M0;
		powB[1][i] = (powB[1][i - 1] * B) % M1;
	}
	return;
};

bool Input() {
	cin >> s;

	return true;
};

void Solve() {
	int sz = s.size();
	int l = 0, r = sz / 2;
	auto Query = [&](int len) {
		LL h0 = 0, h1 = 0;
		LL p0 = powB[0][len], p1 = powB[1][len];
		int cnt = 0;
		for (int i = 0; i < len; i++) {
			h0 = (h0 * B + s[i]) % M0;
			h1 = (h1 * B + s[i]) % M1;
		}
		lookUp[cnt] = { (h0 << 32) | h1, cnt };
		cnt++;
		for (int i = len; i < sz; i++) {
			h0 = (h0 * B + s[i] - (s[i - len] * p0) % M0 + M0) % M0;
			h1 = (h1 * B + s[i] - (s[i - len] * p1) % M1 + M1) % M1;
			lookUp[cnt] = { (h0 << 32) | h1, cnt };
			cnt++;
		}
		sort(lookUp, lookUp + cnt);
		PLL prv = lookUp[0];
		for (int i = 1; i < cnt; i++) {
			if (prv.first != lookUp[i].first) {
				prv = lookUp[i];
			}
			else if (prv.second + len <= lookUp[i].second) {
				return true;
			}
		}
		return false;
	};
	while (l <= r) {
		int m = (l + r) / 2;
		if (Query(m)) {
			mxL = m;
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	return;
};

void Output() {
	println("{}", mxL ? mxL : -1);
	return;
};
