#include<bits/stdc++.h>
#include<ranges>
#include<print>
#include<random>

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
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

deque<Pii> dq;
int A, N, M;

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
	cin >> N >> M;

	M = 2 * M - 1;

	for (int i : Rng(0, M)) {
		cin >> A;
		while (!dq.empty() && dq.back().first < A) {
			dq.pop_back();
		}
		dq.emplace_back(A, i);
	}
	return true;
};

void Solve() {
	return;
};

void Output() {
	print("{}{}", dq.front().first, SEPS[M == N]);
	for (int i : Rng(M, N)) {
		cin >> A;
		while (!dq.empty() && dq.front().second <= i - M) {
			dq.pop_front();
		}
		while (!dq.empty() && dq.back().first < A) {
			dq.pop_back();
		}
		dq.emplace_back(A, i);
		print("{}{}", dq.front().first, SEPS[i == N - 1]);
	}
	return;
};
