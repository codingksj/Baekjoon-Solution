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
	constexpr int MOD = 1E+9 + 9, INF = 0x3f3f3f3f, DIGITS = 10, MAX = 1 << 15, MAX_N = 100'000;
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
void DFS(int depth, LL n, int cnt);
void Output();

V1<LL> factors, addF, subF, v1, v2;
LL yMod[MAX_N + 1] = { 1, };
LL N, Y, Z, y, cnt, sz;

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
	cin >> N >> Y;

	return true;
};

void Solve() {
	for (int n = 1; n <= N; n++) {
		yMod[n] = yMod[n - 1] * Y % MOD;
	}
	y = Y;
	for (LL i = 2; i * i <= Y; ++i) { 
		cnt = 0;
		while (!(y % i)) {
			cnt++;
			y /= i;
		}
		if (cnt) {
			factors.push_back(i);
		}
	}
	if (y > 1) {
		factors.push_back(y);
	}
	DFS(0, 1, 0);
	sz = 1 << (factors.size() - 1);
	v1 = addF, v2 = subF;
	for (int n : Rng(1, N + 1)) {
		LL val = yMod[N - n] * (N - n + 1) % MOD;
		LL sum = 0;
		for (int i = 0; i < sz; i++) {
			sum += v1[i];
			sum -= v2[i];
			if (sum >= MOD) {
				sum -= MOD;
			}
			if (sum < 0) {
				sum += MOD;
			}
			v1[i] = v1[i] * addF[i] % MOD;
			v2[i] = v2[i] * subF[i] % MOD;
		}
		Z = (Z + val * sum) % MOD;
	}
	return;
}

void DFS(int depth, LL n, int cnt) {
	if (depth == factors.size()) {
		(cnt & 1 ? subF : addF).push_back(Y / n);
		return;
	}
	DFS(depth + 1, n * factors[depth], cnt + 1);
	DFS(depth + 1, n, cnt);
};

void Output() {
	println("{}", Z);
	return;
}
