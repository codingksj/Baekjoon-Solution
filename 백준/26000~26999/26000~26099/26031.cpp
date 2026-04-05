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

V1<LL> H, L;
LL peak, h;
int N;

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

	for (int i : Rng(0, N)) {
		cin >> h;
		if (H.empty() || H.back() != h) {
			H.push_back(h);
		}
	}
	return true;
};

void Solve() {
	int sz = H.size();
	L.push_back(H[0]);
	for (int i = 1; i < sz - 1; i++) {
		bool isLocalMn = H[i] < H[i - 1] && H[i] < H[i + 1];
		bool isLocalMx = H[i] > H[i - 1] && H[i] > H[i + 1];
		if (isLocalMn || isLocalMx) {
			L.push_back(H[i]);
		}
	}
	L.push_back(H.back());
	sz = L.size();
	for (int i = 1; i < sz - 1; i++) {
		bool isLocalMx = L[i] > L[i - 1] && L[i] > L[i - 1];
		if(isLocalMx) {
			peak = max(peak, L[i] - max(L[i - 1], L[i + 1]));
		}
	}
	return;
};

void Output() {
	println("{}", peak);
	return;
};
