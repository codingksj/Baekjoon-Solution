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
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 100;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

V1<int> pos[MAX + 1];
int A[MAX + 1];
int tap[MAX + 1];
int tapPos[MAX + 1];
int N, K, v, res;

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

	for (int i : Rng(1, K + 1)) {
		cin >> v;
		A[i] = v;
		pos[v].push_back(i);
	}

	return true;
};

void Solve() {
	for (int i : Rng(1, K + 1)) {
		bool isPlugged = false;
		if (tapPos[A[i]]) {
			isPlugged = true;
		}
		else {
			for (int t : Rng(1, N + 1)) {
				if (!tap[t]) {
					isPlugged = true;
					tap[t] = A[i];
					tapPos[A[i]] = t;
					break;
				}
			}
		}
		if (!isPlugged) {
			res++;
			int maxNxt = -1;
			int tIdx = -1;
			for (int t : Rng(1, N + 1)) {
				int target = tap[t];
				auto it = ranges::upper_bound(pos[target], i);
				int nxt = it == pos[target].end() ? INF : *it;
				if (nxt > maxNxt) {
					maxNxt = nxt;
					tIdx = t;
				}
			}
			tapPos[tap[tIdx]] = 0;
			tap[tIdx] = A[i];
			tapPos[A[i]] = tIdx;
		}
	}
	return;
};

void Output() {
	println("{}", res);
	return;
};
