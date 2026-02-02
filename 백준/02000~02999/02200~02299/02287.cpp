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
enum CONSTS : int { MOD = (int)1E+9 + 7, INF = 0x3f3f3f3f, DIGITS = 10, MAX = 1 << 3 };

unordered_set<LL> dp[MAX + 1];
int K, N, target, mnLen;

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
	cin >> K >> N;

	return true;
};

void Solve() {
	int val = 0;
	for (int i = 1; i <= MAX; i++) {
		val = val * 10 + K;
		dp[i].insert(val);
	}
	for (int i = 1; i <= MAX; i++) {
		for (int j = 1; j < i; j++) {
			for (auto a : dp[j]) {
				for (auto b : dp[i - j]) {
					dp[i].insert(a + b);
					dp[i].insert(a - b);
					dp[i].insert(a * b);
					if (b) {
						dp[i].insert(a / b);
					}
				}
			}
		}
	}
	auto Find = [&](int target) {
		if (target == K) {
			return 1;
		}
		for (int i = 1; i <= MAX; i++) {
			if (dp[i].count(target)) {
				return i;
			}
		}
		return -1;
	};

	for (int i : Rng(0, N)) {
		cin >> target;
		mnLen = Find(target);
		println("{}", mnLen == -1 ? "NO" : to_string(mnLen));
	}
}

void Output() {
	return;
}
