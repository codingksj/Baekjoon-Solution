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
	constexpr int DIGITS = 10, GROUP = 3;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}

using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

V1<PSS> names;
PSS name;
int N, Q;

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

	names.resize(N);

	for (auto& [f, l] : names) {
		cin >> l >> f;
	}

	cin >> Q;

	return true;
};

void Solve() {
	ranges::sort(names);

	while (Q--) {
		cin >> name.second >> name.first;
		int idx = ranges::lower_bound(names, name) - names.begin();
		int st = GROUP * (idx / GROUP);
		int ed = st + GROUP;
		for (int i : Rng(st, ed)) {
			const auto& [f, l] = names[i];
			if (i != idx) {
				println("{} {}", l, f);
			}
		}
	}
	return;
}

void Output() {
	return;
}
