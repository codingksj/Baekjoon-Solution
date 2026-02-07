#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
using ui64 = unsigned long long;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
	constexpr string_view SEPS = " \n";
	constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
	constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 50;
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

V1<string> xray;
int target = 4 * '1';
int N, M;
bool isTumor;

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
	cin >> N >> M;

	xray.resize(N);

	for (int i : Rng(0, N)) {
		cin >> xray[i];
	}

	return true;
};

void Solve() {
	for (int i : Rng(0, N - 1)) {
		for(int j : Rng(0, M - 1)){
			if (xray[i][j] + xray[i][j + 1] + xray[i + 1][j] + xray[i + 1][j + 1] == target) {
				isTumor = true;
				return;
			}
		}
	}
	return;
}

void Output() {
	println("{}", (int)isTumor);
	return;
}
