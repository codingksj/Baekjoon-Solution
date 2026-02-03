#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

namespace CONSTS {
	constexpr int MOD = 1E+9 + 7, INF = 0x3f3f3f3f, DIGITS = 10, MAX = 2000;
	constexpr string_view SEPS = " \n";
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}

using namespace CONSTS;

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
	for (int n : Rng(1, MAX / 2 + 1)) {
		A[n] = 1;
	}
	for (int n : Rng(MAX / 2 + 1, MAX + 1)) {
		A[n] = MAX / 2;
	}
	return;
}

void Output() {
	println("{}", MAX);
	for (int n : Rng(1, MAX + 1)) {
		print("{}{}", A[n], SEPS[n == MAX]);
	}
	return;
}
