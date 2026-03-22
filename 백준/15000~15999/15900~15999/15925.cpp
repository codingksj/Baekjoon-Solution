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
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 31;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

ULL A[MAX];
int rowCnt[MAX];
int colCnt[MAX];
bool isOn, canMake = true;
LL N, bit;

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
	cin >> N >> isOn;

	for (int r : Rng(0, N)) {
		for (int c : Rng(0, N)) {
			cin >> bit;
			A[r] |= (bit << c);
			colCnt[c] += bit;
		}
		rowCnt[r] = popcount(A[r]);
	}

	return true;
};

void Solve() {
	if (!isOn) {
		isOn = !isOn;
		ULL mask = (1LL << N) - 1;
		for (int i : Rng(0, N)) {
			A[i] = ~A[i] & mask;
			rowCnt[i] = N - rowCnt[i];
			colCnt[i] = N - colCnt[i];
		}
	}
	bool isChanged;
	int half = (N + 1) / 2;
	auto UpdateRow = [half, &isChanged]() {
		for (int r : Rng(0, N)) {
			if (rowCnt[r] >= half) {
				for (int c : Rng(0, N)) {
					ULL target = 1LL << c;
					if (!(A[r] & target)) {
						A[r] |= target;
						isChanged = true;
						colCnt[c]++;
					}
				}
				rowCnt[r] = N;
			}
		}
	};
	auto UpdateCol = [half, &isChanged]() {
		for (int c : Rng(0, N)) {
			if (colCnt[c] >= half) {
				for (int r : Rng(0, N)) {
					ULL target = 1LL << c;
					if (!(A[r] & target)) {
						A[r] |= target;
						isChanged = true;
						rowCnt[r]++;
					}
				}
				colCnt[c] = N;
			}
		}
	};
	do {
		isChanged = false;
		UpdateRow();
		UpdateCol();
	} while (isChanged);
	for (int r : Rng(0, N)) {
		for (int c : Rng(0, N)) {
			ULL target = 1LL << c;
			if (!(A[r] & target)) {
				canMake = false;
				return;
			}
		}
	}
	return;
};

void Output() {
	println("{}", (int)canMake);
	return;
};
