#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using Pii = pair<int, int>;
using VPii = vector<Pii>;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

auto Rng = [](auto st, auto ed) { return views::iota(st, ed); };

const int DIGITS = 10;

string s;
int N, x;

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
	cin >> N >> s;

	return true;
};

void Solve() {
	int sum = 0;
	int pos = -1;
	auto GetVal = [](char ch, int i) { 
		int val = ch - '0';  
		return i & 1 ? val : (val >= 5 ? 2 * val - 9 : 2 * val);
	};
	for (int i = N - 2; i >= 0; i--) {
		char& ch = s[i];
		if (ch == 'x') {
			pos = i - (N - 2);
		}
		else {
			sum += GetVal(ch, i - (N - 2));
		}
	}
	if (pos == -1) {
		x = sum * 9 % DIGITS;
	}
	else {
		for (x = 0; x < DIGITS; x++) {
			int val = GetVal(x + '0', pos);
			if ((sum + val) * 9 % DIGITS == (s[N - 1] - '0')) {
				return;
			}
		}
	}
};

void Output() {
	println("{}", x);
}
