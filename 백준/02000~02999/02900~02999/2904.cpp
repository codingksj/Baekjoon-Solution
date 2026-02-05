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
	constexpr int MOD = 1E+9 + 7, INF = 0x3f3f3f3f, DIGITS = 10, MAX = 1 << 15;
	constexpr string_view SEPS = " \n";
	constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}

using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

map<int, int> factors;
V1<map<int, int>> F;
V1<int> V;
int N, mxCnt, mxScore = 1;

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
	cin >> N;

	V.resize(N);
	F.resize(N);

	for (auto& x : V) {
		cin >> x;
	}

	return true;
};

void Solve() {
	for (int n : Rng(0, N)) {
		int v = V[n];
		for (int i = 2; i * i <= v; ++i) { 
			int cnt = 0;
			while (!(v % i)) {
				cnt++;
				v /= i;
			}
			if (cnt) {
				F[n][i] += cnt;
				factors[i] += cnt;
			}
		}
		if (v > 1) {
			F[n][v] += 1;
			factors[v]++;
		}
	}
	auto Pow = [&](int b, int e) { int res = 1; while (e--) { res *= b; } return res; };
	for (const auto& [p, e] : factors) {
		mxScore *= Pow(p, e / N);
		for (auto& mp : F) {
			mxCnt += max(0, e / N - mp[p]);
		}
	}
	return;
}

void Output() {
	println("{} {}", mxScore, mxCnt);
	return;
}
