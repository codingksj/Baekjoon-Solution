#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
using ui64 = unsigned long long;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
	constexpr string_view SEPS = " \n";
	constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
	constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 10;
	constexpr int DIGITS = 10;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}

using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void DFS(int depth);
bool Comp(int sum, char ch);
void Output();

string s;
char M[MAX][MAX];
int A[MAX], st[MAX], ed[MAX], sums[MAX];
int N;
bool isExist;

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
	int idx = 0;
	for (int i : Rng(0, N)) {
		for (int j : Rng(i, N)) {
			M[i][j] = s[idx++];
		}
	}
	for (int i = 0; i < N; i++) {
		char ch = M[i][i];
		st[i] = (ch == '+' ? 1 : (ch == '-' ? -10 : 0));
		ed[i] = (ch == '+' ? 10 : (ch == '-' ? -1 : 0));
	}
	DFS(0);
	return;
}

void DFS(int depth) {
	if (isExist) {
		return;
	}
	if (depth == N) {
		isExist = true;
		return;
	}
	for (int n = st[depth]; n <= ed[depth]; n++) {
		for (int i : Rng(0, depth + 1)) {
			sums[i] += n;
		}
		bool canGo = true;
		for (int i : Rng(0, depth + 1)) {
			if (!Comp(sums[i], M[i][depth])) {
				canGo = false;
				break;
			}
		}
		if (canGo) {
			A[depth] = n;
			DFS(depth + 1);
			if (isExist) {
				return;
			}
		}
		for (int i : Rng(0, depth + 1)) {
			sums[i] -= n;
		}
	}
};

bool Comp(int sum, char ch) { 
	return sum ? sum > 0 ? ch == '+' : ch == '-' : ch == '0'; 
};

void Output() {
	for (int i : Rng(0, N)) {
		print("{}{}", A[i], SEPS[i == N - 1]);
	}
	return;
}
