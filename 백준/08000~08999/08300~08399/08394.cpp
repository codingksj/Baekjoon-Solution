#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using Vi = vector<int>;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

auto Rng = [](auto st, auto ed) { return views::iota(st, ed); };

const int DIGITS = 10;

int N, digit;

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

	return true;
};

void Solve() {
	int d[4] = { 1,1,2,3 };
	if (N < 4) {
		digit = d[N];
		return;
	}
	int a = 2;
	int b = 3;
	int n = a + b;
	for (int i = 0; i < N - 3; i++) {
		n = a + b;
		if (n >= DIGITS) {
			n -= DIGITS;
		}
		a = b;
		b = n;
	}
	digit = n;
};

void Output() {
	println("{}", digit);
}
