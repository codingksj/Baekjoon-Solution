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
	constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 2E+5;
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
V1<int> V, AV;
string dna;
int N, mnDmg;

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
	cin >> N;

	return true;
};

void Solve() {
	auto CalcScore = [&](const string& S, const int MAX_LEN) {
		for (int len = 1; len <= MAX_LEN / 2; len++) {
			int q = MAX_LEN / len;
			int r = MAX_LEN % len;
			if (r) {
				continue;
			}
			bool isSame = true;
			for (int k = 1; k < q && isSame; k++) {
				for (int i = 0; i < len; i++) {
					if (S[i] != S[k * len + i]) {
						isSame = false;
						break;
					}
				}
			}
			if (isSame) {
				return len;
			}
		}
		return MAX_LEN;
	};
	for (int i : Rng(0, N)) {
		cin >> dna;
		V.push_back(CalcScore(dna, dna.size()));
	}
	for (int i : Rng(0, N)) {
		cin >> dna;
		AV.push_back(CalcScore(dna, dna.size()));
	}
	ranges::sort(V);
	ranges::sort(AV);
	for (int i : Rng(0, N)) {
		int d = V[i] - AV[i];
		mnDmg += d * d;
	}
	return;
};

void Output() {
	println("{}", mnDmg);
	return;
};
