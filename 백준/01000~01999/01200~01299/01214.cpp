#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<numbers>
#include<print>

using namespace std;

using LL = long long;
using LD = long double;
using Pii = pair<int, int>;
using TLL3 = tuple<LL, LL, LL>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
	constexpr string_view SEPS = " \n";
	constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
	constexpr LD EPS = 1E-7, PI = numbers::pi;
	constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 500;
	constexpr int DIGITS = 10, ALPHABETS = 26, HOUR = 60, DAY = HOUR * 24;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}

using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

// ---------- 전역 변수 ----------
LL D, P, Q, mnCost;

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
	cin >> D >> P >> Q;

	return true;
};

void Solve() {
	if (P > Q) {
		swap(P, Q);
	}
	auto Ceil = [](LL a, LL b) { return (a + b - 1) / b; };
	if (!(D % P) || !(D % Q) || !(D % (P + Q))) {
		mnCost = D;
		return;
	}
	if (D <= P) {
		mnCost = P;
		return;
	}
	if (D > P && D <= Q) {
		mnCost = min(Q, P * Ceil(D, P));
		return;
	}
	LL g = gcd(P, Q);
	D = (D + g - 1) / g;
	P /= g, Q /= g;
	LL d = D + P;
	LL mxY = min(P, Ceil(D, Q));
	for (LL y = 0; y <= mxY; y++) {
		LL r = D - Q * y;
		if (!r) {
			mnCost = D;
			return;
		}
		LL x = r <= 0 ? 0 : Ceil(r, P);
		LL nd = P * x + Q * y;
		if (nd < d) {
			d = nd;
		}
		if (nd == D) {
			break;
		}
	}
	mnCost = d * g;
	return;
};

void Output() {
	cout << mnCost << "\n";
	return;
};
