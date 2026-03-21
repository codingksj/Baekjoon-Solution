#include<bits/stdc++.h>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
using Ti3 = tuple<int, int, int>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
	constexpr string_view SEPS = " \n";
	constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
	constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f;
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 25'000;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

int dp[2][MAX + 1];
int B[MAX];
int dq[MAX + 1];
int N, M, C, D, res = INF;

int main() {
	FastIO();
	SetUp();

	Input();
	Solve();
	Output();

	return 0;
}

void FastIO() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	return;
};

void SetUp() {
	return;
};

bool Input() {
	cin >> N >> M >> C >> D;

	for (int i : Rng(0, N)) {
		cin >> B[i];
	}

	return true;
};

void Solve() {
	for (int j = 1; j <= M; j++) {
		dp[0][j] = abs(B[0] - j);
	}
	for(int i : Rng(0, N)){
		bool cur = i & 1;
		bool prv = ~i & 1;
		for (int r = 1; r <= C; r++) {
			int head = 0, rear = -1;
			int ed = min(M, r + D);
			for (int j = r; j <= ed; j += C) {
				while (head <= rear && dp[prv][dq[rear]] >= dp[prv][j]) {
					rear--;
				};
				dq[++rear] = j;
			}
			for (int j = r; j <= M; j += C) {
				dp[cur][j] = dp[prv][dq[head]] + abs(B[i] - j);
				int nr = j + D + C;
				if (nr <= M) {
					while (head <= rear && dp[prv][dq[rear]] >= dp[prv][nr]) {
						rear--;
					};
					dq[++rear] = nr;
				}
				while (head <= rear && dq[head] <= j - D) {
					head++;
				}
			}
		}
	}
	for (int i : Rng(1, M + 1)) {
		res = min(res, dp[(N - 1) & 1][i]);
	}
	return;
};

void Output() {
	println("{}", N * M - res);
	return;
};
