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
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 20;
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
int TC, tc, N, mv;

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
	ios::sync_with_stdio(false); cin.tie(nullptr);
	return;
};

void SetUp() {
	return;
};

bool Input() {
	cin >> tc;

	for (int i : Rng(0, MAX)) {
		cin >> A[i];
	}
	return true;
};

void Solve() {
	mv = 0;
	for (int i = 1; i < MAX; i++) {
		int pos = -1;
		for (int j = 0; j < i; j++) {
			if (A[j] > A[i]) {
				pos = j;
				break;
			}
		}
		if (pos != -1) {
			int tmp = A[i];
			for (int j = i - 1; j >= pos; j--) {
				A[j + 1] = A[j];
				mv++;
			}
			A[pos] = tmp;
		}
	}
};

void Output() {
	println("{} {}", tc, mv);
	return;
};
