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
	constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f;
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX_NODE = 32E+5, MAX = 1E+5;
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

int node[MAX_NODE + 1][2];
int N, X, nodeCnt = 1;

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
	auto Insert = [&](int n) {
		int cur = 0;
		for (int i = 30; i >= 0;i--) {
			int b = (n >> i) & 1;
			int& child = node[cur][b];
			if (!child) {
				node[nodeCnt][0] = node[nodeCnt][1] = 0;
				child = nodeCnt++;
			}
			cur = child;
		}
	};
	auto Find = [&](int n) {
		int cur = 0;
		int res = 0;
		for (int i = 30; i >= 0; i--) {
			bool t = (~n >> i) & 1;
			int& child = node[cur][t];
			if (child) {
				res |= (1 << i);
				cur = child;
			}
			else {
				cur = node[cur][!t];
			}
		}
		return res;
	};
	for (int i = 0, n; i < N; i++) {
		cin >> n;
		Insert(n);
		X = max(X, Find(n));
	}
	return;
};

void Output() {
	println("{}", X);
	return;
};
