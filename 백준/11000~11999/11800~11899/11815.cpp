#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

auto rng = [](auto st, auto ed) { return views::iota(st, ed); };

const string_view seps = " \n";
LL X;
int TC, tc;
bool isOdd;

int main() {
	FastIO();
	SetUp();

	cin >> TC;

	while (tc++ < TC) {
		Input();
		Solve();
		Output();
	}

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
	cin >> X;

	return true;
};

void Solve() {
	LL root = round(sqrt(X));
	isOdd = root * root == X;
};

void Output() {
	print("{}{}", (int)isOdd, seps[tc == TC]);
}
