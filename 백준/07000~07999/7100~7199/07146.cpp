#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

namespace CONSTS {
	constexpr int MOD = 1E+9 + 7, INF = 0x3f3f3f3f, DIGITS = 10, MAX = 55;
	constexpr string_view SEPS = " \n";
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}

using namespace CONSTS;

using LL = long long;
using Pii = pair<int, int>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

V1<Pii> datas;
int V = 999;

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
	return true;
};

void Solve() {
	for (int i : Rng(0, MAX - 1)) {
		for (int j : Rng(i + 1, MAX)) {
			datas.push_back({ i, j });
		}
	}
	for (int v : Rng(MAX, MAX + 16)) {
		datas.push_back({ v, v + 1 });
	}
	return;
}

void Output() {
	println("{} {}", V, datas.size());

	for (const auto& [a, b] : datas) {
		println("{} {}", a, b);
	}

	return;
}
