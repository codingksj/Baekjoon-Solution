#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using PLL = pair<LL, LL>;
using Vi = vector<int>;
using VPLL = vector<PLL>;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

auto Rng = [](auto st, auto ed) { return views::iota(st, ed); };

const int DOTS = 4;

VPLL v1, v2;
LL m1, m2, n1, n2;

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
	v1 = VPLL(DOTS);
	for (auto& [x, y] : v1) {
		cin >> x >> y;
	}
	v2 = VPLL(DOTS);
	for (auto& [x, y] : v2) {
		cin >> x >> y;
	}
	return true;
};

void Solve() {
	ranges::sort(v1);
	ranges::sort(v2);
	const auto& [x1, y1] = v1[0];
	const auto& [x2, y2] = v1[DOTS - 1];
	const auto& [x3, y3] = v2[0];
	const auto& [x4, y4] = v2[DOTS - 1];

	m1 = (y3 + y4) - (y1 + y2);
	m2 = (x3 + x4) - (x1 + x2);
	n1 = -(x1 + x2) * m1 + (y1 + y2) * m2;
	n2 = 2 * m2;
	auto g1 = gcd(m1, m2);
	m1 /= g1, m2 /= g1;
	if (m2 < 0) {
		m1 *= -1, m2 *= -1;
	}
	auto g2 = gcd(n1, n2);
	n1 /= g2, n2 /= g2;
	if (n2 < 0) {
		n1 *= -1, n2 *= -1;
	}
};

void Output() {
	print("{}", m1);
	if (m2 != 1 && m1) {
		print("/{}", m2);
	}
	print(" {}", n1);
	if (n2 != 1 && n1) {
		print("/{}", n2);
	}
}
