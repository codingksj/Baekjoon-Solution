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
const int MAX = 500'000;

int res[MAX + 1];
bool isPrimes[MAX + 1];
int N, K;

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
	memset(isPrimes, true, sizeof(isPrimes));
	res[1] = ++K;
	for (LL i = 2; i <= N; i++) {
		if (!isPrimes[i]) {
			continue;
		}
		res[i] = ++K;
		if (i * i > N) {
			continue;
		}
		for (int p = i * i; p <= N; p += i) {
			if (isPrimes[p]) {
				isPrimes[p] = false;
				res[p] = K;
			}
		}
	}
	return;
}

void Output() {
	println("{}", K);
	for (int i : Rng(1, N + 1)) {
		print("{}{}", res[i], SEPS[i == N]);
	}
}
