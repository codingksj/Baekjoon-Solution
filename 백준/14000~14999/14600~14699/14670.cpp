#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<numbers>
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
	constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 100;
	constexpr int DIGITS = 10, ALPHABETS = 26;
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
int medicines[MAX + 1];
int pills[MAX + 1];
int N, R, L, d, m;

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
	memset(medicines, -1, sizeof(medicines));
	return;
};

bool Input() {
	cin >> N;

	while (N--) {
		cin >> d >> m;
		medicines[d] = m;
	}

	cin >> R;

	return true;
};

void Solve() {
	auto CanCure = [&](int L) {
		int cnt = 0;
		bool canCure = true;
		while (L--) {
			cin >> d;
			if (medicines[d] == -1) {
				canCure = false;
			}
			pills[cnt++] = medicines[d];
		}
		return canCure;
	};
	while (R--) {
		cin >> L;
		if (CanCure(L)) {
			for (int i = 0; i < L; i++) {
				print("{}{}", pills[i], SEPS[i == L - 1]);
			}
		}
		else {
			println("YOU DIED");
		}
	}
	return;
};

void Output() {
	return;
};
