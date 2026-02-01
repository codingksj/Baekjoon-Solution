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

LL A, B, res;

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
	cin >> A >> B;

	return true;
};

void Solve() {
	if (A == 1) {
		res = B % P;
		return;
	}
	auto PowMod = [&](LL b, LL e, const LL P) {
		LL res = 1;
		b %= P;
		for (; e; e >>= 1, b = b * b % P) {
			if (e & 1) {
				res = res * b % P;
			}
		}
		return res;
	};
	LL head = (PowMod(A, B, P) + P - 1) % P;
	LL body = PowMod(A - 1, P - 2, P);
	res = head * body % P;
}

void Output() {
	println("{}", res);
}
