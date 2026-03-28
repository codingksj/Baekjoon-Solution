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
	constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 1E+5, MAX_N = 1E+3;
	constexpr int DIGITS = 10, ALPHABETS = 26;
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

Pii A[MAX_N];
V1<int> W, route;
int visChk[MAX + 1];
int N, K, res;

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
	cin >> N >> K;

	for (int i : Rng(0, N)) {
		cin >> A[i].first;
		A[i].second = i + 1;
	}

	return true;
};

void Solve() {
	memset(visChk, -1, sizeof(visChk));
	ranges::sort(A | views::take(N));

	W.reserve(K + 1);
	W.push_back(0);
	int mxW = 0;
	int lastIdx = -1;
	int prvW = -1;
	int cnt = 0;
	
	for (const auto& [a, idx] : A | views::take(N)) {
		int sz = W.size();
		for (int i = 0; i < sz; i++) {
			int nw = W[i] + a;
			if (nw < K) {
				if (visChk[nw] == -1) {
					visChk[nw] = cnt;
					W.push_back(nw);
					mxW = max(mxW, nw);
				}
			}
			else {
				if (nw > mxW) {
					prvW = a;
					mxW = nw;
					lastIdx = idx;
				}
			}
		}
		cnt++;
	}
	res = mxW;
	if (lastIdx != -1) {
		mxW -= prvW;
		route.push_back(lastIdx);
	}
	while (mxW > 0) {
		int idx = visChk[mxW];
		if (idx == -1) {
			break;
		}
		const auto& [w, i] = A[idx];
		route.push_back(i);
		mxW -= w;
	}
	ranges::reverse(route);
	return;
};

void Output() {
	println("{} {}", route.size(), res);
	for (int i : route) {
		print("{}{}", i, SEPS[i == route.back()]);
	}
	return;
};
