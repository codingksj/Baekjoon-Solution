#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using VLL= vector<LL>;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

auto Rng = [](auto st, auto ed) { return views::iota(st, ed); };

const int MAX = 500'000;

string s;
LL dist;
int t[MAX + 1];
int TC, tc, N;

int main() {
	FastIO();
	SetUp();

	cin >> TC;

	while (TC--) {
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
	cin >> N >> s;

	return true;
};

void Solve() {
	int cnt = 0;
	dist = 0;
	for (int i = 0; i < N; i++) {
		const char& ch = s[i];
		if (ch == '1') {
			t[cnt++] = i;
		}
	}
	dist += ((LL)t[0] * (t[0] + 1)) >> 1;
	for (int i = 1; i < cnt; i++) {
		LL p = t[i] - (t[i - 1] + 1);
		LL l = p >> 1;
		LL r = p - (p >> 1);
		dist += (l * (l + 1)) >> 1;
		dist += (r * (r + 1)) >> 1;
	}
	dist += ((LL)(N - 1 - t[cnt - 1]) * (N - t[cnt - 1])) >> 1;
};

void Output() {
	println("Case #{}: {}", ++tc, dist);
}
