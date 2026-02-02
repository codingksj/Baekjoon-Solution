#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
template<typename T> using V1 = vector<T>; 
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V2<V1<T>>;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

constexpr auto Rng = views::iota;
constexpr auto Step = views::stride;

const string SEPS = " \n";
const LL P = 1E+9 + 7;
const int MAX = 200'000;

int TC, X;

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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
};

void SetUp() {
	return;
};

bool Input() {
	cin >> X;

	return true;
};

void Solve() {
	return;
}

void Output() {
	println("1 {} 1 10", X);
}
