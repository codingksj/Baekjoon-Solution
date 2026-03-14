#include<bits/stdc++.h>
#include<ranges>
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
	constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f;
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 100, VAL = 20;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

ULL dp[MAX + 1][VAL + 1];
int A[MAX + 1];
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

	for (int i : Rng(1, N + 1)) {
		cin >> A[i];
	}

	return true;
};

void Solve() {
	dp[1][A[1]] = 1;
	for (int i : Rng(2, N)) {
		for (int val = 0; val <= VAL; val++) {
			if (val >= A[i]) {
				dp[i][val - A[i]] += dp[i - 1][val];
			}
			if (val + A[i] <= VAL) {
				dp[i][val + A[i]] += dp[i - 1][val];
			}
		}
	}
};

void Output() {
	println("{}", dp[N - 1][A[N]]);
	return;
};
