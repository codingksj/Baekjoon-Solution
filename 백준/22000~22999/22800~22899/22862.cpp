#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using Vi = vector<int>;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

auto Rng = [](auto st, auto ed) { return views::iota(st, ed); };

const string SEPS = " \n";
const int MAX = 1E+6;

int S[MAX + 1];
int N, K, cnt, res;

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
	for (int i : Rng(0, N)) {
		cin >> S[i];
	};
	for (int l = 0, r = 0; r < N;) {
		cnt > K ? (S[l++] & 1) && cnt-- : (S[r++] & 1) && cnt++, res = max(res, r - l - cnt);
	}
	return;
}

void Output() {
	println("{}", res);
}
