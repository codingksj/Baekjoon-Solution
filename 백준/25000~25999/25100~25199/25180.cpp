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
enum CONSTS : int { MOD = (int)1E+9 + 7, INF = 0x3f3f3f3f, DIGITS = 10, MAX = 1 << 6, MAX_N = 50 };

int N, mnDigit;

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
	cin >> N;

	return true;
};

void Solve() {
	if (N < 10) {
		mnDigit = 1;
		return;
	}
	int q = N / 9;
	int r = N % 9;
	mnDigit = (~q & 1) ? q + (bool)r : q + (r > 0 ? 1 + (~r & 1) : r);
	return;
}

void Output() {
	println("{}", mnDigit);
	return;
}
