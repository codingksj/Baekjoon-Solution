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

vector<string> res;
string s;

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
	cin >> s;

	return true;
};

void Solve() {
	for (const char& c : s) {
		int sum = 0;
		for (int n = c; n > 0; n /= DIGITS) {
			sum += n % DIGITS;
		}
		res.push_back(string(sum, c));
	}
};

void Output() {
	for (const auto& s : res) {
		println("{}", s);
	}
}
