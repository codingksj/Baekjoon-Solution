#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
	constexpr string_view SEPS = " \n";
	constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
	constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f;
	constexpr int DIGITS = 10, AREA = 20;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}

using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

V2<int> A;
LL cnt;
int tN, tM, N, M, a;
bool isT;

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
	cin >> tN >> tM;

	N = tN, M = tM;

	if (tN > tM) {
		isT = true;
		swap(N, M);
	}
	A = V2<int>(N, V1<int>(M));

	for (int r : Rng(0, tN)) {
		for (int c : Rng(0, tM)) {
			cin >> a;
			(isT ? A[c][r] : A[r][c]) = a;
		}
	}

	return true;
};

void Solve() {
	for (int r1 : Rng(0, N)) {
		for (int r2 : Rng(r1 + 1, N)) {
			int counts[20] = { 0, };
			for (int c : Rng(0, M)) {
				int sum = A[r1][c] + A[r2][c];
				int target = AREA - sum;
				if(target > 1){
					cnt += counts[target];
					counts[sum]++;
				}
			}
		}
	}
	return;
}

void Output() {
	println("{}", cnt);
	return;
}
