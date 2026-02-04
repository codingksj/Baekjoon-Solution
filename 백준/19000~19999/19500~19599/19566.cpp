#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

namespace CONSTS {
	constexpr int MOD = 1E+9 + 7, INF = 0x3f3f3f3f, DIGITS = 10, MAX = 200'000;
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

unordered_map<LL, LL> mp;
LL sum, A, cnt;
int N, K;

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
	mp[0] = 1;
	for (int i : Rng(0, N)) {
		cin >> A;
		sum += A - K;
		mp[sum]++;
	}
	for (const auto& [_, v] : mp) {
		cnt += v * (v - 1) / 2;
	}
	return;
}

void Output() {
	println("{}", cnt);
	return;
}
