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
	constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 12;
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

LL pow10s[MAX] = {1, };
LL N, K, res, d;

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
	for (int i = 1; i <= MAX; i++) {
		pow10s[i] = pow10s[i - 1] * 10;
	}
	return;
};

bool Input() {
	cin >> N >> K;

	return true;
};

void Solve() {
	res = 1;
	K--;
	for (int len = 1; len < MAX; len++){
		LL cnt = 9 * (pow10s[len - 1]);
		if (K >= len * cnt){
			K -= len * cnt;
			res = pow10s[len];
		}
		else {
			LL add = K / len;
			res += add;
			K -= add * len;
			d = res > N ? -1 : to_string(res)[K % len] - '0';
			return;
		}
	}
	return;
};

void Output() {
	println("{}", d);
	return;
};
