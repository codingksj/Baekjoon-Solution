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
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 2E+5;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

int A[MAX];
int N, K, s, e;
bool isExist;

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
	cin >> N >> K;

	for (int i : Rng(0, N)) {
		cin >> A[i];
	}

	return true;
};

void Solve() {
	for (int i = 0; i < N;) {
		int x = 0;
		if ((x | A[i] | K) != K) {
			i++;
			continue;
		}
		s = i;
		while (i < N && ((x | A[i]) | K) == K) {
			x |= A[i];
			e = i++;
		}
		if (x == K) {
			isExist = true;
			return;
		}
	}
	return;
};

void Output() {
	if (isExist) {
		println("{} {}", s + 1, e + 1);
	}
	else {
		println("-1");
	}
	return;
};
