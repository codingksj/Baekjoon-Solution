#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
	constexpr int MOD = 1E+9 + 7, INF = 0x3f3f3f3f, DIGITS = 10, MAX = 1E+5;
	constexpr string_view SEPS = " \n";
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}

using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

V1<int> A, B;
int N, res;

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
	
	A.resize(N);

	for (int i : Rng(0, N)) {
		cin >> A[i];
	}
	return true;
};

void Solve() {
	B.reserve(N * (N + 1) / 2);
	for (int i : Rng(0, N)) {
		for (int j : Rng(i , N)) {
			B.push_back(A[i] + A[j]);
		}
	}
	ranges::sort(B);
	auto [s, e] = ranges::unique(B);
	B.erase(s, e);
	ranges::sort(A, greater<int>());
	for (int i : Rng(0, N)) {
		for (int j : Rng(i + 1, N)) {
			if (ranges::binary_search(B, A[i] - A[j])) {
				res = A[i];
				return;
			};
		}
	}
	return;
}

void Output() {
	println("{}", res);
	return;
}
