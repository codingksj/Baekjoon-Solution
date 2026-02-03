#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using Pii = pair<int, int>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

constexpr auto Rng = views::iota;
constexpr auto Step = views::stride;

const string SEPS = " \n";
enum CONSTS : int { MOD = (int)1E+9 + 7, INF = 0x3f3f3f3f, DIGITS = 10, MAX = 1 << 15, MAX_N = 50 };

int N, cnt, glue = 16667;

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
	return;
}

void Output() {
	if (++cnt <= N) {
		print("{}{}", 1, SEPS[cnt == N]);
	}
	if (++cnt <= N) {
		print("{}{}", glue, SEPS[cnt == N]);
	}
	if (++cnt <= N) {
		print("{}{}", 2 * glue--, SEPS[cnt == N]);
	}
	for (int n = 2; cnt <= N; n++) {
		if (++cnt <= N) {
			print("{}{}", n * glue, SEPS[cnt == N]);
		}
		if (++cnt <= N) {
			print("{}{}", n * glue, SEPS[cnt == N]);
		}
		if (++cnt <= N) {
			print("{}{}", (n + 1) * glue--, SEPS[cnt == N]);
		}
	}
	return;
}
