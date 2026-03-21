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
	constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f;
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 1E+5;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

deque<int> dq;
LL dp[MAX];
LL res = LLONG_MIN;
int N, L, A;

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

	return true;
};

void Solve() {
	for (int i = 0; i < N; i++) {
		cin >> A;

		while (!dq.empty() && dq.front() < i - L) {
			dq.pop_front();
		}
		LL prvMx = dq.empty() ? 0 : max(0LL, dp[dq.front()]);
		dp[i] = A + prvMx;
		if (dp[i] > res) {
			res = dp[i];
		}
		while (!dq.empty() && dp[dq.back()] <= dp[i]) {
			dq.pop_back();
		}
		dq.push_back(i);
	}
	return;
};

void Output() {
	println("{}", res);
	return;
};
