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

int A[MAX];
LL K;
int N, res = 1;

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
	LL h = 0, s = 0;
	int l = A[0];
	int r = A[0];
	int prv = 0;
	for (int i : Rng(1, N)) {
		int a = A[i];
		int nl = min(l, a);
		int nr = max(r, a);
		h = i - prv + 1;
		s = h * (nr - nl + 1);
		if (s > K) {
			res++;
			l = r = a;
			prv = i;
		}
		else {
			l = nl;
			r = nr;
		}
	}
	return;
};

void Output() {
	println("{}", res);
	return;
};
