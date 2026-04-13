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

LL pfA[MAX + 1];
int N, Q, A;

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

	for (int i : Rng(1, N + 1)) {
		cin >> A;
		pfA[i] = pfA[i - 1] + A;
	}
	return true;
};

void Solve() {
	int q, a, b;
	int st = 1;
	auto Query = [&](int a, int b) {
		int l = st + a - 1;
		int r = st + b - 1;
		(l > N) && (l -= N);
		(r > N) && (r -= N);
		return (l <= r) ? pfA[r] - pfA[l - 1] : pfA[N] - pfA[l - 1] + pfA[r] - pfA[0];
	};
	while (Q--) {
		cin >> q >> a;
		if (q == 3) {
			cin >> b;
			println("{}", Query(a, b));
		}
		else {
			st += q == 1 ? N - a : a;
			if (st > N) {
				st -= N;
			}
		}
	}
	return;
};

void Output() {
	return;
};
