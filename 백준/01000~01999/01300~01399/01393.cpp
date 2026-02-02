#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

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

constexpr auto Rng = views::iota;
constexpr auto Step = views::stride;

const string SEPS = " \n";
const LL MOD = 1E+9 + 7;
const int DIGITS = 10;
const int MAX = 200;

int Xs, Ys;
int Xe, Ye, dx, dy, Xj, Yj;
int d, mnD;

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
	cin >> Xs >> Ys;
	cin >> Xe >> Ye >> dx >> dy;

	return true;
};

void Solve() {
	Xj = Xe;
	Yj = Ye;
	if (!dx && !dy) {
		return;
	}
	auto CalcDist = [&](int x1, int y1, int x2, int y2) {
		int dx = x1 - x2, dy = y1 - y2;
		return dx * dx + dy * dy;
	};
	int prv = CalcDist(Xs, Ys, Xe, Ye);
	int g = gcd(dx, dy);
	dx /= g;
	dy /= g;
	mnD = prv;
	for (int i : Rng(0)) {
		int x = Xe + dx * i;
		int y = Ye + dy * i;
		int d = CalcDist(x, y, Xs, Ys);
		if (d > prv) {
			return;
		}
		if (d < mnD) {
			mnD = d;
			Xj = x;
			Yj = y;
		}
		prv = d;
	}
	return;
}

void Output() {
	println("{} {}", Xj, Yj);
}
