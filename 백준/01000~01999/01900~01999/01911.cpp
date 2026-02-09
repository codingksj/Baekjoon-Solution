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
	constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 1.5E+9, MEM = 1E+7;
	constexpr int DIGITS = 10, ALPHABETS = 26;
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
V1<Pii> V;
int N, L, totalCnt, st, ed;

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
	cin >> N >> L;

	V.resize(N);

	for (auto& [x1, x2] : V) {
		cin >> x1 >> x2;
	}

	return true;
};

void Solve() {
	ranges::sort(V);
	int len = V[0].second - V[0].first;
	int cnt =  (len + L - 1) / L;

	totalCnt += cnt;
	ed = len % L ? V[0].first + cnt * L : V[0].second;

	for (int i = 1; i < N; i++) {
		const auto& [x1, x2] = V[i];
		if (x2 < ed) {
			continue;
		}
		st = max(x1, ed);
		len = x2 - st;
		cnt = (len + L - 1) / L;
		totalCnt += cnt;
		ed = len % L ? st + cnt * L : x2;
	}
	return;
};

void Output() {
	println("{}", totalCnt);
	return;
};
