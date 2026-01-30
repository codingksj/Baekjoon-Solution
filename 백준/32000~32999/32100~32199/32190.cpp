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

const string SEPS = " \n";

Vi dp[4];
int N;

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
	dp[2] = { 1,2,1,2 };
	dp[3] = { 2,1,2,3,1,3 };
	return;
};

bool Input() {
	cin >> N;

	return true;
};

void Solve() {
	return;
}

void Output() {
	if (N < 4) {
		for (int i = 0; i < 2 * N; i++) {
			print("{}{}", dp[N][i], SEPS[i == 2 * N - 1]);
		}
		return;
	}
	for (int i = 0; i < N / 2 - 1; i++) {
		int n1 = N - (2 * i + 1);
		int n2 = N - 2 * i;
		print("{} {} {} ", n1, n2, n1);
	}
	int base = 2 + (N & 1);
	for (int i = 0; i < 2 * base; i++) {
		print("{} ", dp[base][i]);
	}
	for (int i = 0; i < N / 2 - 1; i++) {
		int n = base + 2 * (i + 1);
		print("{}{}", n, SEPS[i == N / 2 - 2]);
	}
}
