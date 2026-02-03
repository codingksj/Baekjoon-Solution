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
enum CONSTS : int { MOD = (int)1E+9 + 7, INF = 0x3f3f3f3f, DIGITS = 10, MAX = 1 << 6, MAX_N = 50 };

int B[MAX + 1][MAX + 1];
bool visChk[MAX + 1][MAX + 1];
int N;
bool canGo;

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

	for (int r : Rng(0, N)) {
		for (int c : Rng(0, N)) {
			cin >> B[r][c];
		}
	}

	return true;
};

void Solve() {
	queue<Pii> q;

	q.emplace(0, 0);
	visChk[0][0] = true;

	while (!q.empty()) {
		auto [r, c] = q.front(); q.pop();
		int mv = B[r][c];
		if (mv == -1) {
			canGo = true;
			return;
		}
		int nr = r + mv;
		int nc = c + mv;
		if (nr < N && !visChk[nr][c]) {
			q.emplace(nr, c);
			visChk[nr][c] = true;
		}
		if (nc < N && !visChk[r][nc]) {
			q.emplace(r, nc);
			visChk[r][nc] = true;
		}
	}
	return;
}

void Output() {
	println("{}", canGo ? "HaruHaru" : "Hing");
	return;
}
