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

const int MAX = 500'000;

VPii S;
int N, penalty;

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
	int t, s = -1, mxScore = -1, mxScoreT = 0, idx = -1;
	for (int i = 0; i < N; i++) {
		cin >> t >> s;
		if (s > mxScore) {
			idx = i;
			mxScoreT = t;
			mxScore = s;
		}
	}
	penalty = mxScore ? mxScoreT + 20 * idx : 0;
};

void Output() {
	println("{}", penalty);
}
