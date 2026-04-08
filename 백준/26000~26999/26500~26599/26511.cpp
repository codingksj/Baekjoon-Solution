#include<bits/stdc++.h>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
using Ti3 = tuple<int, int, int>;
using Node = pair<int, char>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
	constexpr string_view SEPS = " \n";
	constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
	constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f;
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 2E+5;
	constexpr auto Rng = views::iota;
	constexpr auto Rev = views::reverse;
	constexpr auto Split = views::split;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

int counts[ALPHABETS];
string s;
int TC, eraser;

int main() {
	FastIO();
	SetUp();

	cin >> TC;

	while (TC--) {
		Input();
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
	cin >> s;

	return true;
};

void Solve() {
	fill(counts, counts + ALPHABETS, INF);
	eraser = 0;
	int diff = 0;
	for (char ch : s) {
		int& cnt = counts[ch - 'a'];
		if (cnt == INF) {
			cnt = 0;
			diff++;
		}
		cnt++;
	}
	sort(counts, counts + ALPHABETS);
	for (int i = 0; i < diff - 2; i++) {
		eraser += counts[i];
	}
	return;
};

void Output() {
	println("{}", eraser);
	return;
};
