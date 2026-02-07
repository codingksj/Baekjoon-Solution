#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
using PSS = pair<string, string>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
	constexpr string_view SEPS = " \n";
	constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
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

V1<int> res;
int N, K;
int t[3] = { 15 * HOUR, 18 * HOUR, 21 * HOUR };

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
	cin >> N >> K;

	return true;
};

void Solve() {
	for (int n : Rng(0, 3)) {
		if (t[n] / DAY == N) {
			res.push_back(t[n] % DAY);
		}
	}
	for (int i : Rng(0, N)) {
		t[0] = t[2] + 18 * HOUR + K;
		t[1] = t[0] + 3 * HOUR;
		t[2] = t[1] + 3 * HOUR;
		for (int n : Rng(0, 3)) {
			if (t[n] / DAY == N) {
				res.push_back(t[n] % DAY);
			}
		}
	}
	ranges::sort(res);
	return;
}

void Output() {
	println("{}", res.size());
	for (auto& t : res) {
		println("{:02}:{:02}", t / 60, t % 60);
	}
	return;
}
