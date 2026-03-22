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

V1<int> G[MAX];
Pii rng[MAX];
int Q, q, cnt;

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
	cin >> Q;

	return true;
};

void Solve() {
	auto BFS = [](int s, int e) {
		queue<int> q;
		bitset<MAX + 1> visChk;
		visChk[s] = 1;
		q.push(s);
		while (!q.empty()) {
			auto v = q.front(); q.pop();
			if (v == e) {
				return 1;
			}
			for (int nv : G[v]) {
				if (!visChk[nv]) {
					visChk[nv] = true;
					q.push(nv);
				}
			}
		}
		return 0;
	};
	int x1, y1;
	while (Q--) {
		cin >> q >> x1 >> y1;
		if (q == 1) {
			rng[cnt] = { x1,y1 };
			for (int i = 0; i < cnt; i++) {
				auto [x2, y2] = rng[i];
				if (x2 < x1 && x1 < y2 || x2 < y1 && y1 < y2) {
					G[cnt].push_back(i);
				}
				if (x1 < x2 && x2 < y1 || x1 < y2 && y2 < y1) {
					G[i].push_back(cnt);
				}
			}
			cnt++;
		}
		else {
			println("{}", BFS(--x1, --y1));
		}
	}
	return;
};

void Output() {
	return;
};
