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

V1<LL> B, res;
LL N, v;

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

	for (int i : Rng(0, N)) {
		cin >> v;
		B.push_back(v);
	}

	return true;
};

void Solve() {
	auto CountN = [&](LL div, LL n) {
		int cnt = 0;
		while (n % div == 0) {
			n /= div;
			cnt++;
		}
		return cnt;
	};

	auto Comp = [&](const LL a, const LL b) {
		int cnt2[2] = { CountN(2, a), CountN(2, b) };
		int cnt3[2] = { CountN(3, a), CountN(3, b) };
		return (cnt2[0] != cnt2[1]) ? cnt2[0] < cnt2[1] : cnt3[0] > cnt3[1];
	};

	ranges::sort(B, Comp);

	return;
}

void Output() {
	for (const auto [i, a] : B | views::enumerate) {
		print("{}{}", a, SEPS[i == N - 1]);
	}

	return;
}
