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
	constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f;
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 2E+5;
	constexpr auto Rng = views::iota;
	constexpr auto Rev = views::reverse;
	constexpr auto Split = views::split;
	constexpr auto Take = views::take;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

int A[MAX];
int N, Q, st, ed;

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
	cin >> N >> Q;

	for (int i : Rng(0, N)) {
		cin >> A[i];
	}
	return true;
};

void Solve() {
	int q, a, b;
	while (Q--) {
		cin >> q >> a;
		if (q == 1) {
			cin >> b;
			a += st - 1;
			if (a >= N) {
				a -= N;
			}
			A[a] += b;
		}
		else {
			int prv = st;
			st += q == 2 ? N - a : a;
			if (st >= N) {
				st -= N;
			}
		}
	}
	ed = (st + N - 1) % N;
	return;
};

void Output() {
	for (int i = st; i < N; i++) {
		print("{}{}", A[i], SEPS[i == ed]);
	}
	for (int i = 0; i < st; i++) {
		print("{}{}", A[i], SEPS[i == ed]);
	}
	return;
};
