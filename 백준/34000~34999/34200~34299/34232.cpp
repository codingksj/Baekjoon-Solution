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
	constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f;
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 1E+6;
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

Pii pos[MAX];
int N, n, cnt;

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

	for (int r : Rng(0, N)) {
		for (int c : Rng(0, N)) {
			cin >> n;
			pos[n - 1] = { r,c };
		}
	}
	return true;
};

void Solve() {
	int mnR = pos[0].first;
	int mnC = pos[0].second;
	int mxR = pos[0].first;
	int mxC = pos[0].second;
	int n = 1;
	for (const auto& [r, c] : pos | Take(N * N)){
		mnR = min(mnR, r), mnC = min(mnC, c);
		mxR = max(mxR, r), mxC = max(mxC, c);
		if (n++ == (mxR - mnR + 1) * (mxC - mnC + 1)) {
			cnt++;
		}
	}
	return;
};

void Output() {
	println("{}", cnt);
	return;
};
