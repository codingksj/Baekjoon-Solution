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

string passwords[MAX];
bool res[MAX];
int TC, A, L, tc, pwIdx, idx1, idx2;
char ch, try1, try2;

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
	cin >> A;
	cin.ignore();

	for (int i : Rng(0, A)) {
		getline(cin, passwords[i]);
		erase(passwords[i], ' ');
	}

	cin >> L;

	return true;
};

void Solve() {
	for (int i : Rng(0, L)) {
		cin >> pwIdx >> idx1 >> idx2 >> try1 >> try2;
		string& target = passwords[--pwIdx];
		res[i] = target[--idx1] == try1 && target[--idx2] == try2;
	}
	return;
}

void Output() {
	println("Customer {}", ++tc);
	for (int i : Rng(0, L)) {
		println("{}", res[i] ? "correct" : "error");
	}
	return;
}
